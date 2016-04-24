#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T16:16:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


LIBS += -L"/home/pi/SFML-master-build/lib" -L /usr/X11R6/lib -lX11
linux-g++{
    message("linux2")
    message($$[QMAKE_SPEC])
}
LIBS += -L"/home/gonyf/.SFML-master/lib"

arm{
    message("arm")
    LIBS += -L"/usr/lib/" -lVEN2
}


CONFIG += c++11
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "/home/pi/.SFML-master/include"
DEPENDPATH += "/home/pi/.SFML-master/include"

INCLUDEPATH += "/home/gonyf/.SFML-master/include"
DEPENDPATH += "/home/gonyf/.SFML-master/include"

TARGET = SFML_Qt
TEMPLATE = app

SOURCES +=  main.cpp\
            Graphics/gps_canvas.cpp \
            Graphics/road.cpp \
            Graphics/sfml_widget.cpp \
            Pages/gps_page.cpp \
            Pages/mainmenu.cpp \
            Pages/mainwindow.cpp \
            Pages/selectscenario.cpp \
            Pages/testpage.cpp
            #VEN/vensend.cpp
arm{
    #SOURCES += vensend.cpp
}

HEADERS  += Graphics/gps_canvas.h \
            Graphics/road.h \
            Graphics/sfml_widget.h \
            Pages/gps_page.h \
            Pages/mainmenu.h \
            Pages/mainwindow.h \
            Pages/selectscenario.h \
            Pages/testpage.h

arm{
    #HEADERS +=  VEN/vensend.h \
     #           VEN/VEN1.h \
      #          VEN/VEN2.h \
       #         VEN/VEN2CommunicationSystem.h \
        #        VEN/VEN2ReceptionFunctor.h
}

FORMS    += page.ui \
            Pages/gps_page.ui \
            Pages/mainmenu.ui \
            Pages/mainwindow.ui \
            Pages/selectscenario.ui \
            Pages/testpage.ui
