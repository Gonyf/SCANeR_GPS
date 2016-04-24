#ifndef TESTPAGE_H
#define TESTPAGE_H

#include <QWidget>
#ifdef __arm__
	#include "vensend.h"
#endif
#include <qdebug.h>
namespace Ui {
class TestPage;
}

class TestPage : public QWidget
{
    Q_OBJECT

public:
	explicit TestPage(QWidget *parent = 0);
    ~TestPage();

private slots:
	//void on_pushButto_Quit_clicked();

    void on_pushButton_Back_clicked();

    void on_pushButton_Launch_clicked();

    void on_pushButton_Play_clicked();

    void on_pushButton_Pause_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_Crash_clicked();

    void on_pushButton_QuitPCApp_clicked();

    void on_pushButton_BadRequest_clicked();

    void on_pushButton_Kill_all_processes_clicked();

	void on_pushButto_Quit_clicked();

signals:
    void back();
	void quit_clicked();
	void rotate10();
	void scrollLeft();
	void scrollRight();
	void scrollUp();
	void scrollDown();

private:
    Ui::TestPage *ui;

	#ifdef __arm__
		VENSend sender;
	#endif
};

#endif // TESTPAGE_H
