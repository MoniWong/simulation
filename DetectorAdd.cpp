#include "DetectorAdd.h"

DetectorAdd::DetectorAdd(QWidget* parent, QTreeWidgetItem* detectorItem) :QDockWidget(parent)
{
	QWidget* Widget = new QWidget;
	Add_ui.setupUi(Widget);
	this->setWidget(Widget);
	this->hide();
	item = detectorItem;
	info = new DetectorInfo;
	*info = item->data(0, Qt::UserRole + 1).value<DetectorInfo>();
	showDetectorInfoUi(info);
	if (info->isdehaze == true)
		Add_ui.dehaze_select_2->setChecked(true);
	connect(Add_ui.pb_select_2, SIGNAL(clicked()), this, SLOT(choosefile()));
	connect(Add_ui.pb_OK, SIGNAL(clicked()), this, SLOT(ok()));
	connect(Add_ui.pb_Cancel, SIGNAL(clicked()), this, SLOT(cancel()));
}


DetectorAdd::~DetectorAdd()
{

}

void DetectorAdd::showDetectorInfoUi(DetectorInfo* detectorinfo)
{
	if (detectorinfo != nullptr)
	{
		Add_ui.le_name_2->setText(detectorinfo->detectorname);
		//Add_ui.le_device_2->setText(detectorinfo->hardware);
		Add_ui.le_pbPath_2->setText(detectorinfo->pbmodel);
		Add_ui.dsb_confidence_2->setValue(detectorinfo->confidencethreshold);
		Add_ui.dsb_NMS_2->setValue(detectorinfo->restrainthreshold);
	}
}

void DetectorAdd::getDetectorInfoUi(DetectorInfo ** detectorinfo)
{

	if (*detectorinfo == nullptr)
		*detectorinfo = new DetectorInfo;

	//*detectorinfo = new DetectorInfo;
	(*detectorinfo)->detectorname = Add_ui.le_name_2->text();
	(*detectorinfo)->hardware = Add_ui.le_device_2->currentText();
	(*detectorinfo)->pbmodel = Add_ui.le_pbPath_2->text();
	(*detectorinfo)->confidencethreshold = Add_ui.dsb_confidence_2->value();
	(*detectorinfo)->restrainthreshold = Add_ui.dsb_NMS_2->value();
}

void DetectorAdd::ok()
{
	getDetectorInfoUi(&info);
	item->setData(0, Qt::UserRole + 1, QVariant::fromValue(*info));
	item->setData(0, Qt::DisplayRole, info->detectorname);
	//emit ok_signal();
}

void DetectorAdd::cancel()
{
	this->close();
	//emit cancel_signal();
}

void DetectorAdd::choosefile() {
	info->pbmodel = QFileDialog::getOpenFileName(this, QStringLiteral("加载模型"),
		"", QStringLiteral("模型文件 (*.pb)"));
	//emit path(pbmodel);
}