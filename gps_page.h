#ifndef GPS_PAGE_H
#define GPS_PAGE_H

#include <QWidget>
#include "gps_canvas.h"

namespace Ui {
class GPS_page;
}

class GPS_page : public QWidget
{
	Q_OBJECT

public:
	explicit GPS_page(QWidget *parent = 0);
	~GPS_page();

private:
	Ui::GPS_page *ui;
	GPS_Canvas *GPS_canvas;
};

#endif // GPS_PAGE_H
