#include "MyFODDetectorGroup.h"


MyFODDetectorGroup::MyFODDetectorGroup(QObject* parent) :QObject(parent)
{
	idx = -1;
}

MyFODDetectorGroup::~MyFODDetectorGroup()
{
	for (auto t : threadList)
	{
		if (t->isRunning())
		{
			t->quit();
			t->wait();
		}
		delete t;
	}
	for (auto t : detectorList)
		delete t;
}

void MyFODDetectorGroup::addModel(DetectorInfo* detectorinfo)
{
	MyFODDetector* t_detector = new MyFODDetector(detectorinfo);
	detectorList.append(t_detector);
	connect(t_detector, SIGNAL(output_result(QString, DetectResult, cv::Mat&, bool)), this, SLOT(get_one(QString, DetectResult, cv::Mat&, bool)));
	connect(this, SIGNAL(loadModel()), t_detector, SLOT(load()));
	connect(t_detector, SIGNAL(loaded(QString, bool)), this, SLOT(model_loaded(QString, bool)));

	QThread* t_thread = new QThread;
	threadList.append(t_thread);
	t_detector->moveToThread(t_thread);
	t_thread->start();
	emit loadModel();
}

void MyFODDetectorGroup::model_loaded(QString myName, bool isLoaded) {
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

void MyFODDetectorGroup::delModel(QString name)
{
	for (auto d : detectorList) {
		if (d->getName() == name) {
			int index = detectorList.indexOf(d);

			if (threadList[index]->isRunning())
			{
				threadList[index]->quit();
				threadList[index]->wait();
			}
			delete threadList[index];
			threadList.removeAt(index);
			delete detectorList[index];
			detectorList.removeOne(d);
		}
	}
}

void MyFODDetectorGroup::get_one(QString name, DetectResult result, cv::Mat& img, bool flag)
{
	emit output_result(name, result, img, flag);
	//disconnect(detectorList[idx], SIGNAL(output_result(DetectResult)), this, SLOT(get_one(DetectResult)));
}

void MyFODDetectorGroup::input_img(QString winName, cv::Mat& img, bool flag)
{
	emit output_img(winName, img, flag);

	if (!detectorList.empty()) {

		idx = (idx + 1) % detectorList.size();
		connect(this, SIGNAL(send_one(QString, cv::Mat&, bool)), detectorList[idx], SLOT(input_img(QString, cv::Mat&, bool)));
		//connect(detectorList[idx], SIGNAL(output_result(DetectResult)), this, SLOT(get_one(DetectResult)));
		emit send_one(winName, img, flag);
		disconnect(this, SIGNAL(send_one(QString, cv::Mat&, bool)), detectorList[idx], SLOT(input_img(QString, cv::Mat&, bool)));
	}
	else
		emit saveImg();
}


