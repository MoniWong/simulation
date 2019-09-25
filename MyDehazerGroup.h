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
	//����MyDehazer��QThread����MyDehazer�Ž�QThread
	void addModel(QString name, QString modelPath, QString device);
	//ɾ����ӦMyDehazer��QThread
	void delModel(QString name);
	//void input_img(QString winName, cv::Mat& img);//����group��
	

public slots:
	void input_img(QString winName, cv::Mat& img, bool flag);//����group��
	void get_one(QString winName, cv::Mat& img, bool flag); //��dehazer���

private slots:
	void model_loaded(QString myName, bool isLoaded);

private:
	QList<MyDehazer*> dehazerList;
	QList<QThread*> threadList;
	int idx;
signals:
	void send_one(QString winName, cv::Mat& img, bool flag); //��ͼ�񷢵�dehazer
	void output_img(QString winName, cv::Mat& img, bool flag);//��group����
	void loadModel();//����ģ���ź�
	void isloaded(QString myName, bool isLoaded);
};