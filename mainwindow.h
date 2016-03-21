#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gps_canvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_pushButton_clicked();

signals:
	void click();

private:
	Ui::MainWindow *ui;
	GPS_Canvas* canvas;
};

#endif // MAINWINDOW_H
