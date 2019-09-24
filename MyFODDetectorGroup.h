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
	//����MyDehazer��QThread����MyDehazer�Ž�QThread
	void addModel(DetectorInfo*);
	//ɾ����ӦMyDehazer��QThread
	void delModel(QString name);


public slots:
	void input_img(QString winName, cv::Mat& img);//����group��
	void get_one(DetectResult); //��detector���

private:
	QList<MyFODDetector*> detectorList;
	QList<QThread*> threadList;
	int idx;
signals:
	void send_one(QString winName, cv::Mat& img); //��ͼ�񷢵�detector
	void output_result(DetectResult);//��group����
	void output_img(QString winName, cv::Mat& img);
};