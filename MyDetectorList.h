#pragma once

#include <QtCore>
#include <QtWidgets>
#include <QMetaType>
#include <QMessageBox>
#include <iostream>
#include <DXGI.h>  
#include <vector> 
#include <opencv2\opencv.hpp>

#include "ui_DetectorAdd.h"
#include "ui_DetectorList.h"
#include "MyDehazerGroup.h"
#include "MyFODDetectorGroup.h"


#include "MyType.h"

#ifdef _DEBUG
#include <QDebug>
#else

#endif


class MyDetectorList : public QDockWidget
{
	Q_OBJECT

public:
	MyDetectorList(QWidget* parent = Q_NULLPTR); //构造函数
	// parent代表父对象，父对象被销毁时这个对象也会被销毁
	~MyDetectorList(); //析构函数

	

	Ui::DetectorListClass detectorInfo_ui;
	// 等价于device里的ui

//public slots:
	//void input_img(cv::Mat img); // 输入图像

private:
	void showDetectorInfoUi(DetectorInfo* detectorinfo);
	void getDetectorInfoUi(DetectorInfo** detectorinfo);

	QTreeWidgetItem* AddTreeRoot(QString name);
	QTreeWidgetItem * AddTreeNode(QTreeWidgetItem *parent, QString name, DetectorInfo *detectorinfo);
	QTreeWidgetItem * derainItem;
	QTreeWidgetItem * dehazeItem;
	QTreeWidgetItem * detectorItem;

	DetectorInfo *info;
	QString file;
	QString modelPath;

	MyDehazerGroup dehazerGroup;
	MyFODDetectorGroup FODDetectorGroup;
	
	Ui::DetectorAddClass detectorAdd_ui;
	// 其他其他变量内容,定义结构存放信息

private slots:
	void a_addDetector();
	void a_editDetector();
	void a_delDetector();
	void choosefile();

	//void a_change(QListWidgetItem*, int);
	void a_load();
	void a_unload();
	//void sendsignal();
	void setPath(QString);

signals:
	void closeSignal();
	//void selectmodel(DetectorInfo* detectorinfo);
	void sendPath(QString);
	void getResult(QString, cv::Mat&, bool); // 在某个窗口显示一幅图，设置是否未保存状态
	void showResult(DetectResult); //在当前窗口， 框出结果
	void showState(QString, int); // 状态栏显示信息 xx秒
};