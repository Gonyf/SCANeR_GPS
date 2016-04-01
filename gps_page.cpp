#include "gps_page.h"
#include "ui_gps_page.h"
#include <qdebug.h>

GPS_page::GPS_page(QWidget *parent) :
	QWidget(parent), //parent class page take the parent of this widget
	ui(new Ui::GPS_page)
{
	ui->setupUi(this);
	GPS_canvas = new GPS_Canvas(ui->GPS_widget);
	//connect(this, SIGNAL(menu_clicked())
	menu = new TestPage;
	layout = new QVBoxLayout;
	layout->setMargin(0);
	layout->addWidget(menu);
	frame = new QFrame(this);
	frame->setLayout(layout);
	frame->setGeometry( (this->size().width() - menu->size().width() ) / 2 ,
						(this->size().height() - menu->size().height() )/ 2,
						 menu->size().width(),
						 menu->size().height() );
	frame->hide();
	connect( this->menu, SIGNAL( quit_clicked() ), this, SLOT( hideMenu() ) );
}

GPS_page::~GPS_page()
{
	delete ui;
}

void GPS_page::on_button_Menu_clicked()
{
	//emit menu_clicked();
	qDebug() << "Menu clicked";
	//layout->addWidget(menu);
	//frame->setLayout(layout);
	frame->show();
}

void GPS_page::showMenu(){
	qDebug() << "Menu clicked";
}

void GPS_page::hideMenu(){
	qDebug() << "hide menu";
	frame->hide();
}
