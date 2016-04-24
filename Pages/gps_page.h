#ifndef GPS_PAGE_H
#define GPS_PAGE_H

#include <QWidget>
#include "../Graphics/gps_canvas.h"
#include "testpage.h"
#include <QVBoxLayout>
#include <QFrame>
#include <thread>
#include "Defines_Structures_Functions.h"


#ifdef __arm__
#include "../VEN/vensend.h"
//#include "VENReceive"
#endif

namespace Ui {
class GPS_page;
}

class GPS_page : public QWidget
{
	Q_OBJECT

public:
	explicit GPS_page(QWidget *parent = 0);
	~GPS_page();

public slots:
	void hideMenu();

	void rotate10();
	void scrollUp();
	void scrollDown();
	void scrollLeft();
	void scrollRight();

signals:
	void menu_clicked();

private slots:
	void on_button_Menu_clicked();

private:
	Ui::GPS_page *ui;

	// Stuff for the GPS canvas
	GPS_Canvas *GPS_canvas;

	// Stuff for the menu box
	TestPage *menu;
	QFrame *menuFrame;
	QVBoxLayout *menuLayout;

	//Stuff for threading for the updating of
	// the position and angle from the SCANeR simulation
	std::thread *updatePositionThread;
	std::thread *updateAngleThread;
	bool stopThread; // When this becomes true the threads will exit their endless while loop causing them to stop
	void getPositionOfCar();
	void getAngleOfCar();
	position carPosition;
	double carAngle;

#ifdef __arm__
    VENSend receiver;
#endif
};

#endif // GPS_PAGE_H
