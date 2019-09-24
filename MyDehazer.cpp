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
	this->model = dehazer::dehazerCreater(modelPath.toStdString(), device.toStdString());
}

 MyDehazer::~MyDehazer()
 {

 }

 QString MyDehazer::getName()
 {
	 return this->name;
 }

 void MyDehazer::input_img(QString winName, cv::Mat& img)
 {
	 model->run(img);
	 emit output_img(winName, img);
 }