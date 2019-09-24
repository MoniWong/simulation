#include "MyDetectResult.h"

MyDetectResult::MyDetectResult(QWidget* parent) :QDockWidget(parent)
{
	this->setAllowedAreas(Qt::BottomDockWidgetArea);
	QWidget* formWidget = new QWidget(this);
	ui.setupUi(formWidget);
	this->setWidget(formWidget);
	this->setWindowTitle(QStringLiteral("设备列表"));

	ui.tw_Result->setHeaderLabels(QStringList() << QStringLiteral("异物类别") << QStringLiteral("置信度"));;
	connect(ui.pb_ClearSelect, SIGNAL(clicked()), this, SLOT(pb_ClearSelect_clicked()));
	connect(ui.pb_ClearAll, SIGNAL(clicked()), this, SLOT(pb_ClearAll_clicked()));
	connect(ui.pb_OutPut, SIGNAL(clicked()), this, SLOT(pb_OutPut_clicked()));
}

MyDetectResult::~MyDetectResult()
{
	
}

void MyDetectResult::SetDock(QMainWindow* dock)
{
	dock->addDockWidget(Qt::BottomDockWidgetArea, this);
}

const DetectResult MyDetectResult::getResult()
{
	return localResult;
}

void MyDetectResult::ShowResultList(DetectResult result)
{
	localResult = result;
	ui.tw_Result->clear();
	for (int i = 0; i < result.num_detections; i++)
	{
		QTreeWidgetItem* t = new QTreeWidgetItem(QStringList()<<QString::number(result.classes_data[i])<< QString::number(result.scores_data[i]));
		ui.tw_Result->addTopLevelItem(t);
	}
}

void MyDetectResult::pb_ClearSelect_clicked()
{
	QModelIndex index = ui.tw_Result->currentIndex();
	if (!index.isValid()) return;
	QTreeWidgetItem* t = ui.tw_Result->takeTopLevelItem(index.row());
	delete t;
}

void MyDetectResult::closeEvent(QCloseEvent* event)
{
	emit closeSignal();
}

void MyDetectResult::pb_ClearAll_clicked()
{
	ui.tw_Result->clear();
}

void MyDetectResult::pb_OutPut_clicked()
{
}