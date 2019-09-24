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

void MyFODDetector::input_img(QString winName, cv::Mat& img)
{
	DetectResult result = model->run(img, info->restrainthreshold, info->confidencethreshold);
	emit output_result(result);
}
