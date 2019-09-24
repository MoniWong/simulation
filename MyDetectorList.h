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
	MyDetectorList(QWidget* parent = Q_NULLPTR); //���캯��
	// parent�������󣬸���������ʱ�������Ҳ�ᱻ����
	~MyDetectorList(); //��������

	

	Ui::DetectorListClass detectorInfo_ui;
	// �ȼ���device���ui

//public slots:
	//void input_img(cv::Mat img); // ����ͼ��

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
	// ����������������,����ṹ�����Ϣ

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
	void getResult(QString, cv::Mat&, bool); // ��ĳ��������ʾһ��ͼ�������Ƿ�δ����״̬
	void showResult(DetectResult); //�ڵ�ǰ���ڣ� ������
	void showState(QString, int); // ״̬����ʾ��Ϣ xx��
};