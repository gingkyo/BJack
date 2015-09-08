#-------------------------------------------------
#
# Project created by QtCreator 2015-09-08T12:57:09
#
#-------------------------------------------------

QT       += core gui
QT       +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cards
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectionmanager.cpp

HEADERS  += mainwindow.h \
    connectionmanager.h

FORMS    += mainwindow.ui
