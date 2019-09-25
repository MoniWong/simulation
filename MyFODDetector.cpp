#include "MyFODDetector.h"

MyFODDetector::MyFODDetector(DetectorInfo* detectorinfo)
{
	//this->name = detectorinfo->detectorname;
	//this->modelPath = detectorinfo->pbmodel;
	//this->device = detectorinfo->hardware;
	this->info = detectorinfo;
	//this->model = FODDetector::FODDetectorCreater(info->pbmodel.toStdString(), info->hardware.toStdString());
}

MyFODDetector::~MyFODDetector()
{
}

QString MyFODDetector::getName()
{
	return this->info->detectorname;
}

bool MyFODDetector::modelEmpty()
{
	if (this->model == nullptr)
		return true;
	else
		return false;
}

void MyFODDetector::load()
{
	model = FODDetector::FODDetectorCreater(info->pbmodel.toStdString(), info->hardware.toStdString());
	if (model == nullptr) {
		emit loaded(info->detectorname, false);
		return;
	}

	cv::Mat t(cv::Size(1920, 1080), CV_8UC3, cv::Scalar(0, 0, 0));
	model->run(t);
	emit loaded(info->detectorname, true);
}

void MyFODDetector::input_img(QString winName, cv::Mat& img, bool flag)
{
	DetectResult result = model->run(img, info->restrainthreshold, info->confidencethreshold);
	emit output_result(winName, result, img, flag);
}
