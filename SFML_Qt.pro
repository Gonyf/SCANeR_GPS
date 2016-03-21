#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T16:16:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -L"/home/gonyf/.SFML-master/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "/home/gonyf/.SFML-master/include"
DEPENDPATH += "/home/gonyf/.SFML-master/include"

TARGET = SFML_Qt
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    sfml_widget.cpp \
    gps_canvas.cpp \
    road.cpp

HEADERS  += mainwindow.h \
    sfml_widget.h \
    gps_canvas.h \
    road.h

FORMS    += mainwindow.ui
