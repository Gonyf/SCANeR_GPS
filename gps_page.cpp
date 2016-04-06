#include "gps_page.h"
#include "ui_gps_page.h"
#include <qdebug.h>

GPS_page::GPS_page(QWidget *parent) :
	QWidget(parent), //parent class page take the parent of this widget
	ui(new Ui::GPS_page)
{
	ui->setupUi(this);
	// Initialize the GPS canvas
	GPS_canvas = new GPS_Canvas(ui->GPS_widget);
	//connect(this, SIGNAL(menu_clicked())

	// Initialize the menu which will be drawn in a frame, making it an overlay menu
	menu = new TestPage; // initilize the menu widget itself
	menuLayout = new QVBoxLayout; // initialize the layout that contains the menu widget
	menuLayout->setMargin(0); // remove the margins of the layout, making the menu widget take up the entire space of the layout
	menuLayout->addWidget(menu);
	menuFrame = new QFrame(this); // initialize the frame that contains the layout and therefore the menu widget
	menuFrame->setLayout(menuLayout);
	menuFrame->setGeometry( (this->size().width() - menu->size().width() ) / 2 , // set size and placement of the frame
						(this->size().height() - menu->size().height() )/ 2,
						 menu->size().width(),
						 menu->size().height() );
	menuFrame->hide(); // the menu hides until user manually asks for the menu overlay

	// Test for the camera of the SFML GPS_canvas view. Should be deleted in due time.
	connect( this->menu, SIGNAL( quit_clicked() ), this, SLOT( hideMenu() ) );
	connect( this->menu, SIGNAL( rotate10() ), this, SLOT( rotate10() ) );
	connect( this->menu, SIGNAL( scrollUp() ), this, SLOT( scrollUp() ) );
	connect( this->menu, SIGNAL( scrollDown() ), this, SLOT( scrollDown() ) );
	connect( this->menu, SIGNAL( scrollLeft() ), this, SLOT( scrollLeft() ) );
	connect( this->menu, SIGNAL( scrollRight() ), this, SLOT( scrollRight() ) );

	// initialize the threads used for obtaining car-position and angle
	carPosition.x	= 0;
	carPosition.y	= 0;
	carAngle		= 0;
	stopThread		= false;
	updatePositionThread	= new std::thread(&GPS_page::getPositionOfCar, this);
	updateAngleThread		= new std::thread(&GPS_page::getAngleOfCar, this);
}

GPS_page::~GPS_page()
{
	stopThread = true;
	delete ui;
}

void GPS_page::on_button_Menu_clicked()
{
	qDebug() << "Menu clicked";
	menuFrame->show();
}

void GPS_page::hideMenu(){
	qDebug() << "hide menu";
	menuFrame->hide();
}
void GPS_page::rotate10(){
	GPS_canvas->setViewRotation(10);
}

void GPS_page::scrollUp(){
	GPS_canvas->setViewCenter(0, 10);
}

void GPS_page::scrollDown(){
	GPS_canvas->setViewCenter(0, -10);
}

void GPS_page::scrollLeft(){
	GPS_canvas->setViewCenter(-10, 0);
}

void GPS_page::scrollRight(){
	GPS_canvas->setViewCenter(10, 0);
}

void GPS_page::getPositionOfCar(){
	while (!stopThread){
	#ifdef __arm__
		position = receiver.getPosition();
	#endif
	}
}
void GPS_page::getAngleOfCar(){
	while (!stopThread){
		#ifdef __arm__
			angle = receiver.getAngle();
		#endif
	}
}
