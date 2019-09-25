#pragma once
#pragma once

#include <opencv2\opencv.hpp>
#include <QtCore>
#include "../derainer/derainer.h"

class MyDerainer : public QObject
{
	Q_OBJECT
private:
	MyDerainer();
	MyDerainer(MyDerainer&);
	QString name;
	QString modelPath;
	QString device;
	derainer* model;
public:
	//MyDehazer(QString name, dehazer* model);
	MyDerainer(QString name, QString modelPath, QString device);
	~MyDerainer();
	QString getName(); //»ñÈ¡Ãû×Ö

public slots:
	void input_img(QString winName, cv::Mat& img, bool flag);
	void load();

signals:
	void output_img(QString winName, cv::Mat& img, bool flag);
	void loaded(QString myName, bool isLoaded);
};