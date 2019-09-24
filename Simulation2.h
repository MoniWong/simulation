#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>

#include <QtCore>
#include <QtWidgets>
#include <QtDebug>

#include "MyProcessList.h"
#include "MySubWindow.h"
#include "ui_Simulation2.h"
#include "ui_SubWindow.h"
#include "ui_PicList.h"


#ifdef _DEBUG

#else

#endif

class Simulation2 : public QMainWindow
{
	Q_OBJECT

public:
	Simulation2(QWidget* parent = Q_NULLPTR);
	~Simulation2();

private:
	Ui::SimulationClass ui;

	QPointer<QObjectCleanupHandler> subWindowsAllCleaner;
	QPointer<QObjectCleanupHandler> subWindowsSavedCleaner;
	QPointer<MyProcessList> processList;

public slots:
	void update_subWin(cv::Mat& image);
	void Creat_newSubWin(QString title, cv::Mat& image);
	void ProcessList_toggled(bool);
	void setPicFalse();
	void close_Pic(QString);

private slots:
	void openPic();

};

Q_DECLARE_METATYPE(cv::Mat)