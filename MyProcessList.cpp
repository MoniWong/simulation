#include "MyProcessList.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>


MyProcessList::MyProcessList(QWidget* parent) :QDockWidget(parent)
{
	QWidget* Widget = new QWidget;
	ui.setupUi(Widget);
	this->setWidget(Widget);
	this->setWindowTitle(QStringLiteral("处理列表"));
	this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	this->hide();

	connect(ui.pB_do, SIGNAL(clicked()), this, SLOT(doProcess()));
	connect(ui.pB_reset, SIGNAL(clicked()), this, SLOT(originPic()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(getPath()));
}

MyProcessList::~MyProcessList()
{
	
}

void MyProcessList::getPic(cv::Mat& Pic)
{
	img = Pic;
	origin_img = Pic;
}

void MyProcessList::closeEvent(QCloseEvent* event)
{
	emit closeSignal();
}

Mat MyProcessList::addfog(double beta, cv::Mat& img)
{
	cv::Mat fog_img = fog(img, beta);
	return fog_img;
}

Mat MyProcessList::addrain(double alpha, std::string path, cv::Mat& img)
{
	cv::Mat rain_img = addRain(img, alpha, path);
	return rain_img;
}

Mat MyProcessList::addsnow(double ext, cv::Mat& img)
{
	cv::Mat snow_img = addSnow(img, ext);
	return snow_img;
}

void MyProcessList::getPath()
{
	QString file = QFileDialog::getExistingDirectory(this, "choose src Directory",
		"/");
	if (file.isEmpty())
		return;
	else
		ui.rain_path->setText(file);
}

void MyProcessList::doProcess()
{
	if (ui.cB_addFog->isChecked()) {
		img = addfog(ui.fog_para->value(), img);
	}
	if (ui.cB_addRain->isChecked()) {
		img = addrain(ui.rain_para->value(), ui.rain_path->text().toStdString(), img);
	}
	if (ui.cB_addSnow->isChecked()) {
		img = addsnow(ui.snow_para->value(), img);
	}
	emit creatWin(img);
}

void MyProcessList::originPic()
{
	emit creatWin(origin_img);
}

