#include "MyDerainer.h"

MyDerainer::MyDerainer(QString name, QString modelPath, QString device)
{
	this->name = name;
	this->modelPath = modelPath;
	this->device = device;
}

MyDerainer::~MyDerainer()
{

}

QString MyDerainer::getName()
{
	return this->name;
}

void MyDerainer::load()
{
	model = derainer::derainerCreator(modelPath.toStdString(), device.toStdString());
	if (model == nullptr) {
		emit loaded(name, false);
		return;
	}

	cv::Mat t(cv::Size(1920, 1080), CV_8UC3, cv::Scalar(0, 0, 0));
	model->run(t);
	emit loaded(name, true);
}

void MyDerainer::input_img(QString winName, cv::Mat& img, bool flag)
{
	cv::Mat t = img.clone();
	model->run(t);
	emit output_img(winName, t, flag);
}