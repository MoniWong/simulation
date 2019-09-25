#pragma once

#include <opencv2\opencv.hpp>
#include <QtCore>
#include "../derainer/derainer.h"
#include "MyDerainer.h"

class MyDerainerGroup : public QObject
{
	Q_OBJECT
public:
	MyDerainerGroup(QObject* parent = Q_NULLPTR);
	~MyDerainerGroup();
	//增加MyDehazer，QThread，把MyDehazer放进QThread
	void addModel(QString name, QString modelPath, QString device);
	//删除对应MyDehazer，QThread
	void delModel(QString name);
	void input_img(QString winName, cv::Mat& img, bool flag);//输入group的


public slots:
	//void input_img(QString winName, cv::Mat& img);//输入group的
	void get_one(QString winName, cv::Mat& img, bool flag); //从derainer获得

private slots:
	void model_loaded(QString myName, bool isLoaded);

private:
	QList<MyDerainer*> dehazerList;
	QList<QThread*> threadList;
	int idx;
signals:
	void send_one(QString winName, cv::Mat& img, bool flag); //把图像发到dehazer
	void output_img(QString winName, cv::Mat& img, bool flag);//从group传出
	void loadModel();//加载模型信号
	void isloaded(QString myName, bool isLoaded);
};