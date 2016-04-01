#ifndef GPS_PAGE_H
#define GPS_PAGE_H

#include <QWidget>
#include "gps_canvas.h"
#include "testpage.h"
#include <QVBoxLayout>
#include <QFrame>

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
	void showMenu();
	void hideMenu();

signals:
	void menu_clicked();

private slots:
	void on_button_Menu_clicked();

private:
	Ui::GPS_page *ui;
	GPS_Canvas *GPS_canvas;


	TestPage *menu;
	QFrame *frame;
	QVBoxLayout *layout;
};

#endif // GPS_PAGE_H
