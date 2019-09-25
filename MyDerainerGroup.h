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
	//����MyDehazer��QThread����MyDehazer�Ž�QThread
	void addModel(QString name, QString modelPath, QString device);
	//ɾ����ӦMyDehazer��QThread
	void delModel(QString name);
	void input_img(QString winName, cv::Mat& img, bool flag);//����group��


public slots:
	//void input_img(QString winName, cv::Mat& img);//����group��
	void get_one(QString winName, cv::Mat& img, bool flag); //��derainer���

private slots:
	void model_loaded(QString myName, bool isLoaded);

private:
	QList<MyDerainer*> dehazerList;
	QList<QThread*> threadList;
	int idx;
signals:
	void send_one(QString winName, cv::Mat& img, bool flag); //��ͼ�񷢵�dehazer
	void output_img(QString winName, cv::Mat& img, bool flag);//��group����
	void loadModel();//����ģ���ź�
	void isloaded(QString myName, bool isLoaded);
};