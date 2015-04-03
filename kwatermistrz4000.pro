#-------------------------------------------------
#
# Project created by QtCreator 2015-03-18T22:33:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kwatermistrz4000
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    modifyhotelwindow.cpp \
    person.cpp \
    room.cpp \
    roombutton.cpp \
    floorbutton.cpp \
    floor.cpp \
    hotel.cpp

HEADERS  += mainwindow.h \
    modifyhotelwindow.h \
    person.h \
    room.h \
    roombutton.h \
    floorbutton.h \
    floor.h \
    hotel.h

FORMS    += mainwindow.ui \
    modifyhotelwindow.ui \

RESOURCES += \
    icons.qrc
