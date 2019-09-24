#pragma once

#include <QtCore>
#include <QtWidgets>
#include <QMetaType>
#include <QMessageBox>

#include "ui_DetectorAdd2.h"

#include "MyType.h"


#ifdef _DEBUG
#include <QDebug>
#else

#endif

class DetectorAdd : public QDockWidget
{
	Q_OBJECT

public:
	DetectorAdd(QWidget* parent = Q_NULLPTR, QTreeWidgetItem* detectorItem = nullptr); //���캯��
	// parent�������󣬸���������ʱ�������Ҳ�ᱻ����
	~DetectorAdd(); //��������



	Ui::Form Add_ui;
	// �ȼ���device���ui



private:
	void showDetectorInfoUi(DetectorInfo* detectorinfo);

	// ����������������,����ṹ�����Ϣ
	void getDetectorInfoUi(DetectorInfo** detectorinfo);
	DetectorInfo* info;
	QTreeWidgetItem* item;

private slots:
	void choosefile();
	void ok();
	void cancel();

signals:
	void path(QString);
	void ok_signal();
	void cancel_signal();
};
