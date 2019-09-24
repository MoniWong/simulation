#pragma once
#pragma once

#include <opencv2\opencv.hpp>
#include <QtCore>
#include "..\FODDetector\FODDetector.h"
#include "MyFODDetector.h"


class MyFODDetectorGroup : public QObject
{
	Q_OBJECT
public:
	MyFODDetectorGroup(QObject* parent = Q_NULLPTR);
	~MyFODDetectorGroup();
	//增加MyDehazer，QThread，把MyDehazer放进QThread
	void addModel(DetectorInfo*);
	//删除对应MyDehazer，QThread
	void delModel(QString name);


public slots:
	void input_img(QString winName, cv::Mat& img);//输入group的
	void get_one(DetectResult); //从detector获得

private:
	QList<MyFODDetector*> detectorList;
	QList<QThread*> threadList;
	int idx;
signals:
	void send_one(QString winName, cv::Mat& img); //把图像发到detector
	void output_result(DetectResult);//从group传出
	void output_img(QString winName, cv::Mat& img);
};