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
#include "MyDerainerGroup.h"


#include "MyType.h"

#ifdef _DEBUG
#include <QDebug>
#else

#endif


class MyDetectorList : public QDockWidget
{
	Q_OBJECT

public:
	MyDetectorList(QWidget* parent = Q_NULLPTR); //���캯��
	// parent�������󣬸���������ʱ�������Ҳ�ᱻ����
	~MyDetectorList(); //��������

	void getPicPath(QStringList);

	Ui::DetectorListClass detectorInfo_ui;
	// �ȼ���device���ui

//public slots:
	//void input_img(cv::Mat img); // ����ͼ��

private:
	QStringList PicPathList;
	cv::Mat img;
	cv::Mat origin_img;
	void showDetectorInfoUi(DetectorInfo* detectorinfo);
	void getDetectorInfoUi(DetectorInfo* detectorinfo);

	QTreeWidgetItem* AddTreeRoot(QString name);
	QTreeWidgetItem * AddTreeNode(QTreeWidgetItem *parent, QString name, DetectorInfo* detectorinfo);

	QTreeWidgetItem* derainerItem;
	QTreeWidgetItem * dehazeItem;
	QTreeWidgetItem * detectorItem;

	QString file;
	QString modelPath;

	MyDerainerGroup* derainerGroup;
	MyDehazerGroup* dehazerGroup;
	MyFODDetectorGroup* FODDetectorGroup;
	
	Ui::DetectorAddClass detectorAdd_ui;
	// ����������������,����ṹ�����Ϣ

	QStringList getDirFilesName(QString );
	bool IsSpecialDir(const char *path);
	bool IsDir(int attrib);
	void ShowError(const char *file_name);
	void GetFilePath(const char *path, const char *file_name, char *file_path);
	void DeleteFile(const char *path);

public slots:
	void setPathList(QStringList);

private slots:
	void a_addDetector();
	void a_editDetector();
	void a_delDetector();
	void choosefile();
	void get_Pic(QString, cv::Mat&, bool);

	//void a_change(QListWidgetItem*, int);
	void a_load();
	void a_unload();
	void a_start();
	//void sendsignal();
	void sendMatToFod(QString, cv::Mat&, bool flag);
	void sendResultToFod(QString, DetectResult, cv::Mat&, bool flag);
	void modelLoaded(QString myName, bool isLoaded);

signals:
	void closeSignal();
	//void selectmodel(DetectorInfo* detectorinfo);
	void getResult(QString, cv::Mat&, bool); // ��ĳ��������ʾһ��ͼ�������Ƿ�δ����״̬
	void showResult(QString, DetectResult, cv::Mat&, bool); //�ڵ�ǰ���ڣ� ������
	void showMat(QString, cv::Mat&, bool);
	void showState(QString, int); // ״̬����ʾ��Ϣ xx��
};