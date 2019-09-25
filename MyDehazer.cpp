#include "MyDehazer.h"

//MyDehazer::MyDehazer(QString name, QString modelPath)
//{
//	this->name = name;
//	this->model = model;
//}

 MyDehazer::MyDehazer(QString name, QString modelPath, QString device)
{
	this->name = name;
	this->modelPath = modelPath;
	this->device = device;
}

 MyDehazer::~MyDehazer()
 {

 }

 QString MyDehazer::getName()
 {
	 return this->name;
 }

 void MyDehazer::load()
 {
	 model = dehazer::dehazerCreater(modelPath.toStdString(), device.toStdString());
	 if (model == nullptr) {
		 emit loaded(name, false);
		 return;
	 }
	 
	 cv::Mat t(cv::Size(1920, 1080), CV_8UC3, cv::Scalar(0, 0, 0));
	 model->run(t);
	 emit loaded(name, true);
 }

 void MyDehazer::input_img(QString winName, cv::Mat& img, bool flag)
 {
	 cv::Mat t = img.clone();
	 model->run(t);
	 emit output_img(winName, t, flag);
 }