#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>

#include <QtCore>
#include <QtWidgets>
#include <QtDebug>

#include "MyProcessList.h"
#include "MySubWindow.h"
#include "MyType.h"
#include "MyDetectResult.h"
#include "MyDetectorList.h"

#include "ui_Simulation2.h"
#include "ui_SubWindow.h"
#include "ui_PicList.h"
#include "ui_DetectorList.h"
#include "ui_DetectorAdd.h"

#ifdef _DEBUG

#else

#endif

class Simulation2 : public QMainWindow
{
	Q_OBJECT

public:
	Simulation2(QWidget* parent = Q_NULLPTR);
	~Simulation2();
	QStringList PicList;

private:
	Ui::SimulationClass ui;

	QPointer<QObjectCleanupHandler> subWindowsAllCleaner;
	QPointer<QObjectCleanupHandler> subWindowsSavedCleaner;
	QPointer<MyProcessList> processList;
	QPointer<MyDetectResult> detectResult;
	QPointer<MyDetectorList> detectorList;

	QStringList  getDirFilesName(QString pathsDir);
	QString file;
	

public slots:
	void update_subWin(QString title, cv::Mat& image);
	void Creat_newSubWin(QString title, cv::Mat& image, bool saved);
	void ProcessList_toggled(bool);
	void a_Detector_toggled(bool);
	void setPicFalse();
	void close_Pic(QString);
	void setDetectorFalse();

private slots:
	void openPic();
	void loadPic();
	void showResult(QString, DetectResult, cv::Mat&, bool);
	void showFinalPic(QString, cv::Mat&, bool);
};

Q_DECLARE_METATYPE(cv::Mat)