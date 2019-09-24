#pragma once

#include <opencv2\opencv.hpp>
#include <QtCore>
#include "../dehazer/dehazer.h"

class MyDehazer : public QObject
{
	Q_OBJECT
private:
	MyDehazer();
	MyDehazer(MyDehazer&);
	QString name;
	QString modelPath; 
	QString device;
	dehazer* model;
public:
	//MyDehazer(QString name, dehazer* model);
	 MyDehazer(QString name, QString modelPath, QString device);
	~MyDehazer();
	QString getName(); //»ñÈ¡Ãû×Ö

public slots:
	void input_img(QString winName, cv::Mat& img);
signals:
	void output_img(QString winName, cv::Mat& img);
};