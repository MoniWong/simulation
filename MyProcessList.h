#pragma once

#include <QtCore>
#include <QtWidgets>
#include <QMetaType>
#include <QMessageBox>


#include "ui_ProcessList.h"
#include "ui_AddFog.h"
#include "ui_AddRain.h"
#include "ui_AddSnow.h"

#include <math.h>
#include <iostream>

#include "fogdll1/fog.h"
#include "AddSnow/AddSnow.h"
#include "AddRain/addRain.h"


#ifdef _DEBUG
#include <QDebug>
#else

#endif


class MyProcessList : public QDockWidget
{
	Q_OBJECT

public:
	MyProcessList(QWidget* parent = Q_NULLPTR); //构造函数
	// parent代表父对象，父对象被销毁时这个对象也会被销毁
	~MyProcessList(); //析构函数
	
	Ui::ProcessListClass ui;
	// 其他数据获取和修改方法
	void getPic(QStringList);
	void setPicNum(int);



private:
	void closeEvent(QCloseEvent* event);

	Ui::AddFogClass addfog_ui;
	Ui::AddRainClass addrain_ui;
	Ui::AddSnowClass addsnow_ui;
	cv::Mat img;
	cv::Mat origin_img;
	QStringList pathList;
	double psnr(cv::Mat& I1, cv::Mat& I2);
	double ssim(cv::Mat& i1, cv::Mat& i2);
	bool IsSpecialDir(const char *path);
	bool IsDir(int attrib);
	void ShowError(const char *file_name);
	void GetFilePath(const char *path, const char *file_name, char *file_path);
	void DeleteFile(const char *path);
	QStringList getDirFilesName(QString);


private slots:
	Mat addfog(double, cv::Mat&);
	Mat addrain(double, std::string, cv::Mat&);
	Mat addsnow(double, cv::Mat&);

	void getPath();

	void doProcess();
	//void originPic();



signals:
	void closeSignal();
	void creatWin(QString, cv::Mat&, bool);
	void sendItemName(QString);
	void afterAddPathList(QStringList);
};