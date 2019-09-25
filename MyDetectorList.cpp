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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <direct.h>
#include <errno.h>


using namespace std;



MyDetectorList::MyDetectorList(QWidget* parent) :QDockWidget(parent)
{
	QWidget* Widget = new QWidget;
	detectorInfo_ui.setupUi(Widget);
	this->setWidget(Widget);
	this->setWindowTitle(QStringLiteral("ģ���б�"));
	this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	this->hide();

	derainerItem = AddTreeRoot(QStringLiteral("ȥ��"));
	dehazeItem = AddTreeRoot(QStringLiteral("ȥ��"));
	detectorItem = AddTreeRoot(QStringLiteral("���"));

	derainerGroup = new MyDerainerGroup();
	dehazerGroup = new MyDehazerGroup();
	FODDetectorGroup = new MyFODDetectorGroup();

	connect(derainerGroup, SIGNAL(isloaded(QString, bool)), this, SLOT(modelLoaded(QString, bool)));
	connect(dehazerGroup, SIGNAL(isloaded(QString, bool)), this, SLOT(modelLoaded(QString, bool)));
	connect(FODDetectorGroup, SIGNAL(isloaded(QString, bool)), this, SLOT(modelLoaded(QString, bool)));

	connect(detectorInfo_ui.pb_Add, SIGNAL(clicked()), this, SLOT(a_addDetector()));
	connect(detectorInfo_ui.pb_Edit, SIGNAL(clicked()), this, SLOT(a_editDetector()));
	connect(detectorInfo_ui.pb_Del, SIGNAL(clicked()), this, SLOT(a_delDetector()));
	connect(detectorInfo_ui.pb_unload, SIGNAL(clicked()), this, SLOT(a_unload()));
	connect(detectorInfo_ui.pb_load, SIGNAL(clicked()), this, SLOT(a_load()));
	connect(detectorInfo_ui.pb_start, SIGNAL(clicked()), this, SLOT(a_start()));
	//connect(this, SIGNAL(sendCommand(QTreeWidgetItem*, int)), this, SLOT(a_change(QTreeWidgetItem*, int)));

	//ȥ��group��ͼƬ��ȥ��group
	connect(derainerGroup, SIGNAL(output_img(QString, cv::Mat&, bool)), dehazerGroup, SLOT(input_img(QString, cv::Mat&, bool)));
	//ȥ��group��ͼƬ�����group
	connect(dehazerGroup, SIGNAL(output_img(QString, cv::Mat&, bool)), FODDetectorGroup, SLOT(input_img(QString, cv::Mat&, bool)));
	//�Ӽ��group����ͼƬ
	connect(FODDetectorGroup, SIGNAL(output_img(QString, cv::Mat&, bool)), this, SLOT(sendMatToFod(QString, cv::Mat&, bool)));
	connect(FODDetectorGroup, SIGNAL(output_result(QString, DetectResult, cv::Mat&, bool)), this, SLOT(sendResultToFod(QString, DetectResult, cv::Mat&, bool)));

	QFile file("detectorinfo.txt");
	file.open(QIODevice::ReadWrite);
	QTextStream txtInput(&file);
	QString txt = txtInput.readAll();
	QStringList list = txt.split("\r\n");
	for (int i = 0;i < (list.count() - 1) / 7;i++) {
		DetectorInfo* info = new DetectorInfo;
		info->detectorname = list[i * 7];
		info->hardware = list[i * 7 + 1];
		info->pbmodel = list[i * 7 + 2];
		info->confidencethreshold = list[i * 7 + 3].toDouble();
		info->restrainthreshold = list[i * 7 + 4].toDouble();
		QVariant tempValue1 = list[i * 7 + 5];
		info->isdehaze = tempValue1.toBool();
		QVariant tempValue2 = list[i * 7 + 6];
		info->isderain = tempValue2.toBool();
		info->isload = false;
		if (!info->isdehaze && info->isderain) {
			AddTreeNode(derainerItem, QString(info->detectorname), info);
		}
		if (info->isdehaze && !info->isderain) {
			AddTreeNode(dehazeItem, QString(info->detectorname), info);
		}
		if (!info->isdehaze && !info->isderain) {
			AddTreeNode(detectorItem, QString(info->detectorname), info);
		}
		//delete info;
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
		auto t_item = (DetectorInfo*)(*it)->data(0, Qt::UserRole + 1).value<qulonglong>();
		if (t_item == NULL) {
			++it;
			continue;
		}
		txtOutput << t_item->detectorname << endl;
		txtOutput << t_item->hardware << endl;
		txtOutput << t_item->pbmodel << endl;
		txtOutput << t_item->confidencethreshold << endl;
		txtOutput << t_item->restrainthreshold << endl;
		txtOutput << QString::number(t_item->isdehaze) << endl;
		txtOutput << QString::number(t_item->isderain) << endl;
		++it;
	}
	f.close();

	//ModelList delete model
}

void MyDetectorList::getPicPath(QStringList Pic)
{
	PicPathList = Pic;
	if (PicPathList.size() == 2) {
		cv::Mat t = cv::imread(PicPathList[0].toLocal8Bit().toStdString());
		img = t.clone();
		origin_img = t.clone();
	}
	else
		return;
}

void MyDetectorList::setPathList(QStringList Pic) 
{
	if (!PicPathList.isEmpty())
		PicPathList.clear();
	PicPathList = Pic;
}

void MyDetectorList::a_addDetector()
{
	QPointer<QDialog> addDialog = new QDialog();
	detectorAdd_ui.setupUi(addDialog);
	DetectorInfo* info = new DetectorInfo;

	connect(detectorAdd_ui.pb_select, SIGNAL(clicked()), this, SLOT(choosefile()));

	showDetectorInfoUi(info);

	int res = addDialog->exec();
	if (res == QDialog::Accepted)
	{
		getDetectorInfoUi(info);
		if (info != nullptr)
		{
			if (detectorAdd_ui.derainer_select->isChecked()) {
				info->isderain = true;
				info->isdehaze = false;
				AddTreeNode(derainerItem, QString(info->detectorname), info);
			}
			if (detectorAdd_ui.detector_select->isChecked()) {
				info->isdehaze = false;
				info->isderain = false;
				AddTreeNode(detectorItem, QString(info->detectorname), info);
			}
			if (detectorAdd_ui.dehaze_select->isChecked()) {
				info->isdehaze = true;
				info->isderain = false;
				AddTreeNode(dehazeItem, QString(info->detectorname), info);
			}

			
		}
		delete addDialog;
		addDialog.clear();
	}
}


void MyDetectorList::a_editDetector()
{
	QTreeWidgetItem* currentItem = detectorInfo_ui.tw_Detectors->currentItem();
	if (currentItem == nullptr) return;
	DetectorInfo* info = (DetectorInfo*)currentItem->data(0, Qt::UserRole + 1).value<qulonglong>();
	if (currentItem == dehazeItem || currentItem == detectorItem || currentItem == derainerItem) return;
	QPointer<QDialog> editDialog = new QDialog();
	detectorAdd_ui.setupUi(editDialog);
	showDetectorInfoUi(info);
	//if (info->isdehaze == true)
	//	detectorAdd_ui.dehaze_select->setChecked(true);

	if (!info->isdehaze && info->isderain) {
		detectorAdd_ui.derainer_select->setChecked(true);
	}
	if (info->isdehaze && !info->isderain) {
		detectorAdd_ui.dehaze_select->setChecked(true);
	}
	if (!info->isdehaze && !info->isderain) {
		detectorAdd_ui.detector_select->setChecked(true);
	}
	
	connect(detectorAdd_ui.pb_select, SIGNAL(clicked()), this, SLOT(choosefile()));

	int res = editDialog->exec();
	if (res == QDialog::Accepted)
	{
		getDetectorInfoUi(info);
		currentItem->setData(0, Qt::UserRole + 1, QVariant::fromValue((qulonglong)info));
		currentItem->setData(0, Qt::DisplayRole, info->detectorname);
	}
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
	else if (currentItem == derainerItem)
		return;
	else
	{
		delete (DetectorInfo*)currentItem->data(0, Qt::UserRole + 1).value<qulonglong>();
		delete currentItem->parent()->takeChild(detectorInfo_ui.tw_Detectors->currentIndex().row());
	}
		
}

void MyDetectorList::choosefile()
{
	QString pbmodel = QFileDialog::getOpenFileName(this, QStringLiteral("����ģ��"),
		"", QStringLiteral("ģ���ļ� (*.pb)"));
	detectorAdd_ui.le_pbPath->setText(pbmodel);
}

void MyDetectorList::get_Pic(QString name , cv::Mat& frame, bool flag)
{
	derainerGroup->input_img(name, frame, flag);
}

//void MyDetectorList::a_change(QListWidgetItem *, int)
//{
//}

void MyDetectorList::a_load()
{
	QTreeWidgetItem * currentItem = detectorInfo_ui.tw_Detectors->currentItem();
	if (currentItem == dehazeItem || currentItem == detectorItem || currentItem == derainerItem || currentItem == nullptr) return;
	DetectorInfo* detectorinfo = (DetectorInfo*)currentItem->data(0, Qt::UserRole + 1).value<qulonglong>();
	//qDebug() << detectorinfo->isload;
	if (detectorinfo->isload == true) return;

	QFile file(detectorinfo->pbmodel);
	if (file.exists())
	{
		//qDebug() << "exist";
		bool load = true;

		//�жϱ���ӽڵ��isload�ı�־
		QTreeWidgetItemIterator it(detectorInfo_ui.tw_Detectors);
		while (*it) {
			auto t_item = (DetectorInfo*)(*it)->data(0, Qt::UserRole + 1).value<qulonglong>();
			if (t_item != NULL && t_item->isload == true && detectorinfo->hardware == t_item->hardware 
				&& t_item->isdehaze == detectorinfo->isdehaze && t_item->isderain == detectorinfo->isderain) {
					load = false;
			}
			++it;
		}

		if (load) {
			QIcon item_ico("./Resources/loading.png");
			currentItem->setIcon(0, item_ico);

			if (detectorinfo->isdehaze)
				dehazerGroup->addModel(detectorinfo->detectorname, detectorinfo->pbmodel, detectorinfo->hardware);
			else if (detectorinfo->isderain)
				derainerGroup->addModel(detectorinfo->detectorname, detectorinfo->pbmodel, detectorinfo->hardware);
			else
				FODDetectorGroup->addModel(detectorinfo);
		}
		else {
			QMessageBox::information(nullptr, "ERROR", QStringLiteral("�Ѿ�������ͬ���͵�ģ��!"),
				QMessageBox::Ok);
		}

	}
	else
		QMessageBox::information(nullptr, "ERROR", QStringLiteral("�ļ�������!"),
			QMessageBox::Ok);
}

void MyDetectorList::a_unload()
{
	QTreeWidgetItem * currentItem = detectorInfo_ui.tw_Detectors->currentItem();
	if (currentItem == dehazeItem || currentItem == detectorItem || currentItem == derainerItem || currentItem == nullptr) return;
	DetectorInfo* detectorinfo = (DetectorInfo*)currentItem->data(0, Qt::UserRole + 1).value<qulonglong>();
	if (detectorinfo == nullptr || detectorinfo->isload == false) return;
	// ѭ��ģ��
	if (detectorinfo->isdehaze)
		dehazerGroup->delModel(detectorinfo->detectorname);
	else if (detectorinfo->isderain)
		derainerGroup->delModel(detectorinfo->detectorname);
	else
		FODDetectorGroup->delModel(detectorinfo->detectorname);
	detectorinfo->isload = false;
	QIcon item_ico("./Resources/stop.png");
	currentItem->setIcon(0, item_ico);
}

void MyDetectorList::a_start()
{
	if (PicPathList.size() == 2) {
		cv::Mat pic = cv::imread(PicPathList[0].toLocal8Bit().toStdString());
		get_Pic(PicPathList[1], pic, true);
	}
	else if (PicPathList.size() > 2)
	{
		DeleteFile("C:/Users/ASUS/source/repos/Simulation/afterDetect");
		QApplication::setOverrideCursor(Qt::WaitCursor);//�������Ϊ�ȴ�״̬
		QProgressDialog progress;
		progress.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		progress.setLabelText(QString::fromLocal8Bit("���ڴ�����..."));
		progress.setCancelButtonText(QString::fromLocal8Bit("ȡ��"));
		progress.setRange(0, PicPathList.size() - 1);//���÷�Χ
		progress.setModal(true);//����Ϊģ̬�Ի���
		progress.show();

		QString dir = PicPathList[PicPathList.size() - 1] + "/";

		int iSucceed = 0;
		for (int i = 0; i < PicPathList.size() - 1; i++) {

			QString item = dir + PicPathList[i];
			cv::Mat pic = cv::imread(item.toLocal8Bit().toStdString());
			get_Pic(PicPathList[i], pic, false);
			progress.setValue(i);
			iSucceed = iSucceed + 1;
			if (progress.wasCanceled())
			{
				break;
			}
			QCoreApplication::processEvents();
		}
		QApplication::restoreOverrideCursor();
		progress.close();
		QMessageBox::warning(this, QStringLiteral("��ʾ"), QString::fromLocal8Bit("������%1���ļ���").arg(iSucceed));

	}
	else
		return;
}

QStringList  MyDetectorList::getDirFilesName(QString pathsDir)
{
	QDir dir(pathsDir);
	dir.setFilter(QDir::Files | QDir::NoSymLinks);
	QStringList filters;
	filters << "*.png" << "*.jpg";
	dir.setNameFilters(filters);
	QStringList allImageNameList = dir.entryList();
	if (allImageNameList.count() <= 0)
	{
		QMessageBox::information(nullptr, "ERROR", QStringLiteral("�ļ���Ϊ��!"),
			QMessageBox::Ok);
	}
	return allImageNameList;
}


void MyDetectorList::sendMatToFod(QString name, cv::Mat& frame, bool flag)
{
	emit showMat(name, frame, flag);
}

void MyDetectorList::sendResultToFod(QString name,DetectResult result, cv::Mat& img, bool flag)
{
	emit showResult(name, result, img, flag);
}

void MyDetectorList::modelLoaded(QString myName, bool isLoaded)
{
	QList<QTreeWidgetItem*> t_list = detectorInfo_ui.tw_Detectors->findItems(myName, Qt::MatchContains | Qt::MatchRecursive, 0);
	for (auto t : t_list) {
		if (isLoaded) {
			DetectorInfo* detectorinfo = (DetectorInfo*)t->data(0, Qt::UserRole + 1).value<qulonglong>();
			detectorinfo->isload = true;
			QIcon item_ico("./Resources/start.png");
			t->setIcon(0, item_ico);
		}
		else {
			QMessageBox::information(nullptr, "ERROR", QStringLiteral("ģ�ͼ���ʧ��!"),
				QMessageBox::Ok);
			QIcon item_ico("./Resources/stop.png");
			t->setIcon(0, item_ico);
		}
	}
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
	vector<std::string> deviceList = pb::pbLoader::getDeviceList();
	//vector<std::string> deviceList = { "/:cpu0" };
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

void MyDetectorList::getDetectorInfoUi(DetectorInfo* detectorinfo)
{
	QString name = detectorAdd_ui.le_name->text();
		detectorinfo->detectorname = name;
		detectorinfo->hardware = detectorAdd_ui.le_device->currentText();
		detectorinfo->pbmodel = detectorAdd_ui.le_pbPath->text();
		detectorinfo->confidencethreshold = detectorAdd_ui.dsb_confidence->value();
		detectorinfo->restrainthreshold = detectorAdd_ui.dsb_NMS->value();

}

QTreeWidgetItem * MyDetectorList::AddTreeRoot(QString name)
{
	QTreeWidgetItem * item = new QTreeWidgetItem(QStringList() << name);
	detectorInfo_ui.tw_Detectors->addTopLevelItem(item);
	return item;
}

QTreeWidgetItem * MyDetectorList::AddTreeNode(QTreeWidgetItem * parent, QString name, DetectorInfo* detectorinfo)
{
	QTreeWidgetItem * item = new QTreeWidgetItem(QStringList() << name);
	auto t_value = QVariant::fromValue((qulonglong)detectorinfo);
	item->setData(0, Qt::UserRole + 1, t_value);
	QIcon item_ico("./Resources/stop.png");
	item->setIcon(0,item_ico);
	parent->addChild(item);
	return item;
}

bool MyDetectorList::IsSpecialDir(const char *path)
{
	return strcmp(path, "..") == 0 || strcmp(path, ".") == 0;
}

//�ж��ļ�������Ŀ¼�����ļ�
bool MyDetectorList::IsDir(int attrib)
{
	return attrib == 16 || attrib == 18 || attrib == 20;
}

//��ʾɾ��ʧ��ԭ��
void MyDetectorList::ShowError(const char *file_name = NULL)
{
	errno_t err;
	_get_errno(&err);
	switch (err)
	{
	case ENOTEMPTY:
		printf("Given path is not a directory, the directory is not empty, or the directory is either the current working directory or the root directory.\n");
		break;
	case ENOENT:
		printf("Path is invalid.\n");
		break;
	case EACCES:
		printf("%s had been opend by some application, can't delete.\n", file_name);
		break;
	}
}

void MyDetectorList::GetFilePath(const char *path, const char *file_name, char *file_path)
{
	strcpy_s(file_path, sizeof(char) * _MAX_PATH, path);
	file_path[strlen(file_path) - 1] = '\0';
	strcat_s(file_path, sizeof(char) * _MAX_PATH, file_name);
}

//�ݹ�����Ŀ¼���ļ���ɾ��
void MyDetectorList::DeleteFile(const char *path)
{
	char pcSearchPath[_MAX_PATH];
	sprintf_s(pcSearchPath, _MAX_PATH, "%s\\*", path); //pcSearchPath Ϊ����·����* ����ͨ���

	_finddata_t DirInfo; //�ļ�����Ϣ
	_finddata_t FileInfo; //�ļ���Ϣ
	intptr_t f_handle; //���Ҿ��

	char pcTempPath[_MAX_PATH];
	if ((f_handle = _findfirst(pcSearchPath, &DirInfo)) != -1)
	{
		while (_findnext(f_handle, &FileInfo) == 0)
		{
			if (IsSpecialDir(FileInfo.name))
				continue;
			if (FileInfo.attrib & _A_SUBDIR)//�����Ŀ¼������������·��
			{
				GetFilePath(pcSearchPath, FileInfo.name, pcTempPath);
				DeleteFile(pcTempPath); //��ʼ�ݹ�ɾ��Ŀ¼�е�����
				if (FileInfo.attrib == 20)
					printf("This is system file, can't delete!\n");
				else
				{
					//ɾ����Ŀ¼�������ڵݹ鷵��ǰ����_findclose,�����޷�ɾ��Ŀ¼
					if (_rmdir(pcTempPath) == -1)
					{
						ShowError();//Ŀ¼�ǿ������ʾ����ԭ��
					}
				}
			}
			else
			{
				strcpy_s(pcTempPath, pcSearchPath);
				pcTempPath[strlen(pcTempPath) - 1] = '\0';
				strcat_s(pcTempPath, FileInfo.name);//�����������ļ�·��

				if (remove(pcTempPath) == -1)
				{
					ShowError(FileInfo.name);
				}

			}
		}
		_findclose(f_handle);//�رմ򿪵��ļ���������ͷŹ�����Դ�������޷�ɾ����Ŀ¼
	}
	else
	{
		ShowError();//��·�������ڣ���ʾ������Ϣ
	}
}


