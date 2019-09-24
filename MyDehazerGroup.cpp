#include "MyDehazerGroup.h"

MyDehazerGroup::MyDehazerGroup(QObject* parent):QObject(parent)
{
	idx = -1;
}

MyDehazerGroup::~MyDehazerGroup()
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
	for (auto t : dehazerList)
		delete t;
}

void MyDehazerGroup::addModel(QString name, QString modelPath, QString device)
{
	//if (model == nullptr)
	//	return;
	MyDehazer* t_dehazer = new MyDehazer(name, modelPath, device);
	dehazerList.append(t_dehazer);
	QThread* t_thread = new QThread;
	threadList.append(t_thread);
	connect(t_dehazer, SIGNAL(output_img(QString, cv::Mat&)), this, SLOT(get_one(QString, cv::Mat&)));
	t_dehazer->moveToThread(t_thread);
	t_thread->start();
}

void MyDehazerGroup::delModel(QString name)
{
	for (auto d : dehazerList) {
		if (d->getName() == name) {
			int index = dehazerList.indexOf(d);
			//dehazerList.removeOne(d);
			//threadList.removeAt(index);
			delete dehazerList[index];
			delete threadList[index];
		}
	}
}

void MyDehazerGroup::get_one(QString winName, cv::Mat & img)
{
	emit output_img(winName, img);
	disconnect(dehazerList[idx], SIGNAL(output_img(QString, cv::Mat&)), this, SLOT(get_one(QString, cv::Mat&)));
}

void MyDehazerGroup::input_img(QString winName, cv::Mat& img)
{
	if (dehazerList.empty())
		emit output_img(winName, img);
	idx = (idx + 1) % dehazerList.size();
	connect(this, SIGNAL(send_one(QString, cv::Mat&)), dehazerList[idx], SLOT(input_img(QString, cv::Mat&)));
	emit send_one(winName, img);
	disconnect(this, SIGNAL(send_one(QString, cv::Mat&)), dehazerList[idx], SLOT(input_img(QString, cv::Mat&)));
	connect(dehazerList[idx], SIGNAL(output_img(QString, cv::Mat&)), this, SLOT(get_one(QString, cv::Mat&)));
}