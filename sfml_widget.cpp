#include "sfml_widget.h"
#ifdef Q_WS_X11
	#include <Qt/qx11info_x11.h>
	#include <X11/Xlib.h>
#endif
#include <QDebug>

SFML_Widget::SFML_Widget(QWidget *parent) : QWidget(parent)
{
	// Setup some states to allow direct rendering into the widget
	setAttribute(Qt::WA_PaintOnScreen); // Tells Qt that we will not use its painting functions
	// Prevent drawing from the widgets background, which can cause flickering
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAttribute(Qt::WA_NoSystemBackground);

	// Set strong focus to enable keyboard events to be received
	setFocusPolicy(Qt::StrongFocus);
	// Setup the timer
	frameTimer.setInterval(60);

	resize(QSize(800,640));
	//slet denne kommentar
}

SFML_Widget::SFML_Widget(QWidget *Parent, const QPoint &Position, const QSize &Size, unsigned int FrameTime)
:	QWidget(Parent),
	myInitialized (false)
{
	// Setup some states to allow direct rendering into the widget
	setAttribute(Qt::WA_PaintOnScreen); // Tells Qt that we will not use its painting functions
	// Prevent drawing from the widgets background, which can cause flickering
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAttribute(Qt::WA_NoSystemBackground);

	// Set strong focus to enable keyboard events to be received
	setFocusPolicy(Qt::StrongFocus);

	// Setup the widget geometry
	move(Position);
	resize(Size);

	// Setup the timer
	frameTimer.setInterval(FrameTime);
}

SFML_Widget::~SFML_Widget(){

}
void SFML_Widget::OnInit(){

}

void SFML_Widget::OnUpdate(){

}

void SFML_Widget::showEvent(QShowEvent*){
	if(!myInitialized){
		// Under x11, we need to flush the commands sent to the server to ensure that
		// SFML will get an updated view of the windows
		#ifdef Q_WS_X11
			XFlush(QX11Info::display());
		#endif

		// Create the SFML window with the widget handle
		sf::RenderWindow::create(winId());

		// Let the derived class do its specific stuff
		OnInit();

		// Setup the timer to trigger a refresh at a specified framerate
		connect(&frameTimer, SIGNAL(timeout()), this, SLOT(repaint()));
		frameTimer.start();

		myInitialized = true;
	}
}

void SFML_Widget::paintEvent(QPaintEvent*){
	// Let the derived class do its specific stuff
	OnUpdate();

	// Display on screen
	display();
}
QPaintEngine* SFML_Widget::paintEngine() const{
	return 0;
}
void SFML_Widget::moveMap(){
	qDebug() << "nooooooooooooo!!!!!!!!!!!!!";
}
