#pragma once

#include <opencv2\opencv.hpp>
#include <QtCore>
#include "..\FODDetector\FODDetector.h"
#include "MyType.h"

class MyFODDetector : public QObject
{
	Q_OBJECT
private:
	MyFODDetector();
	MyFODDetector(MyFODDetector&);
	DetectorInfo* info;
	//QString name;
	//QString modelPath;
	//QString device;
	FODDetector* model;
public:
	//MyDehazer(QString name, dehazer* model);
	MyFODDetector(DetectorInfo*);
	~MyFODDetector();
	QString getName(); //»ñÈ¡Ãû×Ö
	bool modelEmpty();

public slots:
	void input_img(QString winName, cv::Mat& img, bool flag);
	void load();

signals:
	void output_result(QString, DetectResult, cv::Mat& img, bool flag);
	void loaded(QString myName, bool isLoaded);
};
