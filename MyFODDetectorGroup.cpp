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
	QThread* t_thread = new QThread;
	threadList.append(t_thread);
	connect(t_detector, SIGNAL(output_img(DetectResult)), this, SLOT(get_one(DetectResult)));
	t_detector->moveToThread(t_thread);
	t_thread->start();
}

void MyFODDetectorGroup::delModel(QString name)
{
	for (auto d : detectorList) {
		if (d->getName() == name) {
			int index = detectorList.indexOf(d);
			//dehazerList.removeOne(d);
			//threadList.removeAt(index);
			delete detectorList[index];
			delete threadList[index];
		}
	}
}

void MyFODDetectorGroup::get_one(DetectResult result)
{
	emit output_result(result);
	disconnect(detectorList[idx], SIGNAL(output_result(DetectResult)), this, SLOT(get_one(DetectResult)));
}

void MyFODDetectorGroup::input_img(QString winName, cv::Mat& img)
{
	if (detectorList.empty())
		emit output_img(winName, img);
	idx = (idx + 1) % detectorList.size();
	connect(this, SIGNAL(send_one(QString, cv::Mat&)), detectorList[idx], SLOT(input_img(QString, cv::Mat&)));
	emit send_one(winName, img);
	disconnect(this, SIGNAL(send_one(QString, cv::Mat&)), detectorList[idx], SLOT(input_img(QString, cv::Mat&)));
	connect(detectorList[idx], SIGNAL(output_result(DetectResult)), this, SLOT(get_one(DetectResult)));
}


