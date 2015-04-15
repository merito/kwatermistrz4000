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
    floor.cpp \
    hotel.cpp \
    modifyfloorwindow.cpp \
    modifyroomwindow.cpp \
    searchwindow.cpp

HEADERS  += mainwindow.h \
    modifyhotelwindow.h \
    person.h \
    room.h \
    floor.h \
    hotel.h \
    modifyfloorwindow.h \
    modifyroomwindow.h \
    searchwindow.h

FORMS    += mainwindow.ui \
    modifyhotelwindow.ui \
    modifyfloorwindow.ui \
    modifyroomwindow.ui \
    searchwindow.ui

RESOURCES += \
    icons.qrc
