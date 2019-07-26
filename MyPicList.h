#pragma once

#include <QtCore>
#include <QtWidgets>
#include <QMetaType>
#include <QMessageBox>


#include "ui_PicList.h"
#include "ui_AddFog.h"
#include "ui_AddRain.h"
#include "ui_AddSnow.h"

#include <math.h>
#include <iostream>
#include <MyType.h>

#include "fogdll1/fog.h"
#include "AddSnow/AddSnow.h"
#include "AddRain/addRain.h"


#ifdef _DEBUG
#include <QDebug>
#else

#endif


class MyPicList : public QDockWidget
{
	Q_OBJECT

public:
	MyPicList(QWidget* parent = Q_NULLPTR); //构造函数
	// parent代表父对象，父对象被销毁时这个对象也会被销毁
	~MyPicList(); //析构函数
	
	Ui::PicListClass ui;
	// 其他数据获取和修改方法



private:
	void closeEvent(QCloseEvent* event);

	Ui::AddFogClass addfog_ui;
	Ui::AddRainClass addrain_ui;
	Ui::AddSnowClass addsnow_ui;

private slots:
	void addFog();
	void addrain();
	void addsnow();
	void openPic();
	void delPic();
	void getPath();


signals:
	void closeSignal();
	void creatWin(QString, cv::Mat&);
	void sendItemName(QString);
};