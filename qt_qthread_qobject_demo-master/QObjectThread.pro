#-------------------------------------------------
#
# Project created by QtCreator 2016-02-04T18:30:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QObjectThread
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    worker.cpp

HEADERS  += widget.h \
    worker.h

FORMS    += widget.ui
