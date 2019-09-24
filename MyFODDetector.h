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

public slots:
	void input_img(QString winName, cv::Mat& img);
signals:
	void output_result(DetectResult);
};
