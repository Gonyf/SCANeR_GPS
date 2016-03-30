#include "gps_page.h"
#include "ui_gps_page.h"
#include <qdebug.h>

GPS_page::GPS_page(QWidget *parent) :
	QWidget(parent), //parent class page take the parent of this widget
	ui(new Ui::GPS_page)
{
	ui->setupUi(this);
	GPS_canvas = new GPS_Canvas(ui->GPS_widget);
}

GPS_page::~GPS_page()
{
	delete ui;
}
