#include "MyDehazerGroup.h"

#define DEHAZER_MULTI_THREAD

MyDehazerGroup::MyDehazerGroup(QObject* parent):QObject(parent)
{
	idx = -1;
}

MyDehazerGroup::~MyDehazerGroup()
{
#ifdef DEHAZER_MULTI_THREAD
	for (auto t : threadList)
	{
		if (t->isRunning())
		{
			t->quit();
			t->wait();
		}
		delete t;
	}
#endif //  DEHAZER_MULTI_THREAD
	for (auto t : dehazerList)
		delete t;
}

void MyDehazerGroup::addModel(QString name, QString modelPath, QString device)
{
	//if (model == nullptr)
	//	return;
	MyDehazer* t_dehazer = new MyDehazer(name, modelPath, device);
	dehazerList.append(t_dehazer);
	connect(t_dehazer, SIGNAL(output_img(QString, cv::Mat&, bool)), this, SLOT(get_one(QString, cv::Mat&, bool)));
	connect(this, SIGNAL(loadModel()), t_dehazer, SLOT(load()));
	connect(t_dehazer, SIGNAL(loaded(QString , bool )), this, SLOT(model_loaded(QString , bool)));
#ifdef DEHAZER_MULTI_THREAD
	QThread* t_thread = new QThread;
	threadList.append(t_thread);
	t_dehazer->moveToThread(t_thread);
	t_thread->start();
	emit loadModel();
#endif // DEHAZER_MULTI_THREAD						
}

void MyDehazerGroup::model_loaded(QString myName, bool isLoaded) {
	if (isLoaded) {
		//发送加载成功信号到list
		emit isloaded(myName, true);
	}
	else {
		//发送加载失败信号到list，并且删除模型
		emit isloaded(myName, false);
		delModel(myName);
	}
}

void MyDehazerGroup::delModel(QString name)
{
	for (auto d : dehazerList) {
		if (d->getName() == name) {
#ifdef DEHAZER_MULTI_THREAD
			int index = dehazerList.indexOf(d);
			if (threadList[index]->isRunning())
			{
				threadList[index]->quit();
				threadList[index]->wait();
			}
			delete threadList[index];
			threadList.removeAt(index);
#endif // DEHAZER_MULTI_THREAD
			delete d;
			dehazerList.removeOne(d);
		}
	}
}

void MyDehazerGroup::get_one(QString winName, cv::Mat & img, bool flag)
{
	emit output_img(winName, img, flag);
}

void MyDehazerGroup::input_img(QString winName, cv::Mat& img, bool flag)
{

	if (dehazerList.empty())
		emit output_img(winName, img, flag);
	else {
		idx = (idx + 1) % dehazerList.size();
		connect(this, SIGNAL(send_one(QString, cv::Mat&, bool)), dehazerList[idx], SLOT(input_img(QString, cv::Mat&, bool)));
		emit send_one(winName, img, flag);
		disconnect(this, SIGNAL(send_one(QString, cv::Mat&, bool)), dehazerList[idx], SLOT(input_img(QString, cv::Mat&, bool)));
	}
}

#undef DEHAZER_MULTI_THREAD