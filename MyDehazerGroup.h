#pragma once

#include <opencv2\opencv.hpp>
#include <QtCore>
#include "../dehazer/dehazer.h"
#include "MyDehazer.h"

class MyDehazerGroup : public QObject
{
	Q_OBJECT
public:
	MyDehazerGroup(QObject* parent = Q_NULLPTR);
	~MyDehazerGroup();
	//增加MyDehazer，QThread，把MyDehazer放进QThread
	void addModel(QString name, QString modelPath, QString device);
	//删除对应MyDehazer，QThread
	void delModel(QString name);
	

public slots:
	void input_img(QString winName, cv::Mat& img);//输入group的
	void get_one(QString winName, cv::Mat& img); //从dehazer获得

private:
	QList<MyDehazer*> dehazerList;
	QList<QThread*> threadList;
	int idx;
signals:
	void send_one(QString winName, cv::Mat& img); //把图像发到dehazer
	void output_img(QString winName, cv::Mat& img);//从group传出
};