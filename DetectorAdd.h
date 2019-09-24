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
	DetectorAdd(QWidget* parent = Q_NULLPTR, QTreeWidgetItem* detectorItem = nullptr); //构造函数
	// parent代表父对象，父对象被销毁时这个对象也会被销毁
	~DetectorAdd(); //析构函数



	Ui::Form Add_ui;
	// 等价于device里的ui



private:
	void showDetectorInfoUi(DetectorInfo* detectorinfo);

	// 其他其他变量内容,定义结构存放信息
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
