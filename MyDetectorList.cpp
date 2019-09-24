#include "MyDetectorList.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include "MSP_Commands.h"
#include "MyDehazer.h"
#include "../pbLoader/pbLoader.h"

using namespace std;



MyDetectorList::MyDetectorList(QWidget* parent) :QDockWidget(parent)
{
	info = nullptr;
	QWidget* Widget = new QWidget;
	detectorInfo_ui.setupUi(Widget);
	this->setWidget(Widget);
	this->setWindowTitle(QStringLiteral("检测器列表"));
	this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	this->hide();

	derainItem = AddTreeRoot(QStringLiteral("去雨"));
	dehazeItem = AddTreeRoot(QStringLiteral("去雾"));
	detectorItem = AddTreeRoot(QStringLiteral("检测"));

	connect(detectorInfo_ui.pb_Add, SIGNAL(clicked()), this, SLOT(a_addDetector()));
	connect(detectorInfo_ui.pb_Edit, SIGNAL(clicked()), this, SLOT(a_editDetector()));
	connect(detectorInfo_ui.pb_Del, SIGNAL(clicked()), this, SLOT(a_delDetector()));
	connect(detectorInfo_ui.pb_unload, SIGNAL(clicked()), this, SLOT(a_unload()));
	connect(detectorInfo_ui.pb_load, SIGNAL(clicked()), this, SLOT(a_load()));
	//connect(this, SIGNAL(sendCommand(QTreeWidgetItem*, int)), this, SLOT(a_change(QTreeWidgetItem*, int)));

	QFile file("detectorinfo.txt");
	file.open(QIODevice::ReadWrite);
	QTextStream txtInput(&file);
	QString txt = txtInput.readAll();
	QStringList list = txt.split("\r\n");
	for (int i = 0;i < (list.count() - 1) / 6;i++) {
		DetectorInfo *info = new DetectorInfo;
		info->detectorname = list[i * 6];
		info->hardware = list[i * 6 + 1];
		info->pbmodel = list[i * 6 + 2];
		info->confidencethreshold = list[i * 6 + 3].toDouble();
		info->restrainthreshold = list[i * 6 + 4].toDouble();
		QVariant tempValue = list[i * 6 + 5];
		info->isdehaze = tempValue.toBool();
		info->isload = false;
		if (info->isdehaze) {
			AddTreeNode(dehazeItem, QString(info->detectorname), info);
		}
		else
			AddTreeNode(detectorItem, QString(info->detectorname), info);

		delete info;
	}
	file.close();
}

MyDetectorList::~MyDetectorList()
{
	QFile f("detectorinfo.txt");

	f.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
	QTextStream txtOutput(&f);
	QTreeWidgetItemIterator it(detectorInfo_ui.tw_Detectors);
	while (*it) {
		if ((*it)->data(0, Qt::UserRole + 1).value<DetectorInfo>().detectorname == "") {
			++it;
			continue;
		}
		txtOutput << (*it)->data(0, Qt::UserRole + 1).value<DetectorInfo>().detectorname << endl;
		txtOutput << (*it)->data(0, Qt::UserRole + 1).value<DetectorInfo>().hardware << endl;
		txtOutput << (*it)->data(0, Qt::UserRole + 1).value<DetectorInfo>().pbmodel << endl;
		txtOutput << (*it)->data(0, Qt::UserRole + 1).value<DetectorInfo>().confidencethreshold << endl;
		txtOutput << (*it)->data(0, Qt::UserRole + 1).value<DetectorInfo>().restrainthreshold << endl;
		txtOutput << QString::number((*it)->data(0, Qt::UserRole + 1).value<DetectorInfo>().isdehaze) << endl;
		++it;
	}
	f.close();

	//ModelList delete model
}

void MyDetectorList::a_addDetector()
{
	QPointer<QDialog> addDialog = new QDialog();
	detectorAdd_ui.setupUi(addDialog);
	DetectorInfo* detectorinfo = new DetectorInfo;
	info = detectorinfo;
	
	connect(detectorAdd_ui.pb_select, SIGNAL(clicked()), this, SLOT(choosefile()));
	connect(this, SIGNAL(sendPath(QString)), this, SLOT(setPath(QString)));
	
	showDetectorInfoUi(info);

	connect(detectorAdd_ui.pb_select, SIGNAL(clicked()), this, SLOT(choosefile()));
	connect(this, SIGNAL(sendPath(QString)), this, SLOT(setPath(QString)));

	int res = addDialog->exec();
	if (res == QDialog::Accepted)
	{
		getDetectorInfoUi(&info);
		if (info != nullptr)
		{
			if (detectorAdd_ui.detector_select->isChecked()) {
				info->isdehaze = false;
				AddTreeNode(detectorItem, QString(info->detectorname), info);
			}
			if (detectorAdd_ui.dehaze_select->isChecked()) {
				info->isdehaze = true;
				AddTreeNode(dehazeItem, QString(info->detectorname), info);
			}
			
		}
		info = nullptr;
		delete detectorinfo;
		
	}
	delete addDialog;
	addDialog.clear();
}


void MyDetectorList::a_editDetector()
{
	QTreeWidgetItem* currentItem = detectorInfo_ui.tw_Detectors->currentItem();
	if (currentItem == nullptr) return;
	DetectorInfo* detectorinfo = new DetectorInfo;
	*detectorinfo = currentItem->data(0, Qt::UserRole + 1).value<DetectorInfo>();
	info = detectorinfo;
	if (currentItem == dehazeItem || currentItem == detectorItem) return;
	QPointer<QDialog> editDialog = new QDialog();
	detectorAdd_ui.setupUi(editDialog);
	showDetectorInfoUi(info);
	if (detectorinfo->isdehaze == true)
		detectorAdd_ui.dehaze_select->setChecked(true);
	
	connect(detectorAdd_ui.pb_select, SIGNAL(clicked()), this, SLOT(choosefile()));
	connect(this, SIGNAL(sendPath(QString)), this, SLOT(setPath(QString)));

	int res = editDialog->exec();
	if (res == QDialog::Accepted)
	{
		getDetectorInfoUi(&info);
		currentItem->setData(0, Qt::UserRole + 1, QVariant::fromValue(*info));
		currentItem->setData(0, Qt::DisplayRole, info->detectorname);
	}
	info = nullptr;
	delete detectorinfo;
	delete editDialog;
	editDialog.clear();
}

void MyDetectorList::a_delDetector()
{
	QTreeWidgetItem * currentItem = detectorInfo_ui.tw_Detectors->currentItem();
	if (currentItem == nullptr)
		return;
	else if (currentItem == dehazeItem)
		return;
	else if (currentItem == detectorItem)
		return;
	else
		delete currentItem->parent()->takeChild(detectorInfo_ui.tw_Detectors->currentIndex().row());
}

void MyDetectorList::choosefile()
{
	QString pbmodel = QFileDialog::getOpenFileName(this, QStringLiteral("加载模型"),
		"", QStringLiteral("模型文件 (*.pb)"));
	emit sendPath(pbmodel);
}

//void MyDetectorList::a_change(QListWidgetItem *, int)
//{
//}

void MyDetectorList::a_load()
{
	QTreeWidgetItem * currentItem = detectorInfo_ui.tw_Detectors->currentItem();
	if (currentItem == dehazeItem || currentItem == detectorItem) return;
	DetectorInfo* detectorinfo = new DetectorInfo;
	*detectorinfo = currentItem->data(0, Qt::UserRole + 1).value<DetectorInfo>();
	if (detectorinfo->isload == true) return;
	QFile file(detectorinfo->pbmodel);
	if (file.exists())
	{
		//qDebug() << "exist";
		detectorinfo->isload = true;
		bool load = true;

		//判断别的子节点的isload的标志
		QTreeWidgetItemIterator it(detectorInfo_ui.tw_Detectors);
		while (*it) {
			if ((*it)->data(0, Qt::UserRole + 1).value<DetectorInfo>().isload == true & (detectorinfo->isdehaze == (*it)->data(0, Qt::UserRole + 1).value<DetectorInfo>().isdehaze)) {
				load = false;
			}
			++it;
		}
		if (load) {
			//加载模型
			if(detectorinfo->isdehaze)
				dehazerGroup.addModel(detectorinfo->detectorname, detectorinfo->pbmodel, detectorinfo->hardware);
			else
				FODDetectorGroup.addModel(detectorinfo);
		}
		else {
			QMessageBox::information(nullptr, "ERROR", QStringLiteral("已经加载相同类型的模型!"),
				QMessageBox::Ok | QMessageBox::Ok);
		}
		QIcon item_ico("./Resources/start.png");
		currentItem->setIcon(0, item_ico);
	}
	else
		QMessageBox::information(nullptr, "ERROR", QStringLiteral("文件不存在!"),
			QMessageBox::Ok | QMessageBox::Ok);

	
}

void MyDetectorList::a_unload()
{
	QTreeWidgetItem * currentItem = detectorInfo_ui.tw_Detectors->currentItem();
	DetectorInfo* detectorinfo = new DetectorInfo;
	*detectorinfo = currentItem->data(0, Qt::UserRole + 1).value<DetectorInfo>();
	if (detectorinfo->isload == false) return;
	// 循环模型
	if (detectorinfo->isdehaze)
		dehazerGroup.delModel(detectorinfo->detectorname);
	else
		FODDetectorGroup.delModel(detectorinfo->detectorname);
	
	QIcon item_ico("./Resources/stop.png");
	currentItem->setIcon(0, item_ico);
}

//void MyDetectorList::sendsignal()
//{
	//emit selectmodel(info);
//}

void MyDetectorList::setPath(QString path)
{
	info->pbmodel = path;
	detectorAdd_ui.le_pbPath->setText(info->pbmodel);
}

void MyDetectorList::showDetectorInfoUi(DetectorInfo* detectorinfo)
{
	if (detectorinfo != nullptr)
	{
		detectorAdd_ui.le_name->setText(detectorinfo->detectorname);
		detectorAdd_ui.le_pbPath->setText(detectorinfo->pbmodel);
		detectorAdd_ui.dsb_confidence->setValue(detectorinfo->confidencethreshold);
		detectorAdd_ui.dsb_NMS->setValue(detectorinfo->restrainthreshold);
	}
	int index=0;
	//vector<std::string> deviceList = pb::pbLoader::getDeviceList();
	vector<std::string> deviceList = { "/:cpu0" };
	QStringList device_List;
	for (auto device : deviceList) {
		device_List << QString::fromStdString(device);
	}
	for (auto device : device_List) {
		if (device == detectorinfo->hardware) {
			break;
		}
		index++;
	}
	detectorAdd_ui.le_device->clear();
	detectorAdd_ui.le_device->addItems(device_List);
	detectorAdd_ui.le_device->setCurrentIndex(index);
}

void MyDetectorList::getDetectorInfoUi(DetectorInfo** detectorinfo)
{
	(*detectorinfo)->detectorname = detectorAdd_ui.le_name->text();
	(*detectorinfo)->hardware = detectorAdd_ui.le_device->currentText();
	(*detectorinfo)->pbmodel = detectorAdd_ui.le_pbPath->text();
	(*detectorinfo)->confidencethreshold = detectorAdd_ui.dsb_confidence->value();
	(*detectorinfo)->restrainthreshold = detectorAdd_ui.dsb_NMS->value();
	
}

QTreeWidgetItem * MyDetectorList::AddTreeRoot(QString name)
{
	QTreeWidgetItem * item = new QTreeWidgetItem(QStringList() << name);
	detectorInfo_ui.tw_Detectors->addTopLevelItem(item);
	return item;
}

QTreeWidgetItem * MyDetectorList::AddTreeNode(QTreeWidgetItem * parent, QString name, DetectorInfo *detectorinfo)
{
	QTreeWidgetItem * item = new QTreeWidgetItem(QStringList() << name);
	item->setData(0, Qt::UserRole + 1, QVariant::fromValue(*detectorinfo));
	QIcon item_ico("./Resources/stop.png");
	item->setIcon(0,item_ico);
	parent->addChild(item);
	return item;
}


