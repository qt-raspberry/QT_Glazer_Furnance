#-------------------------------------------------
#
# Project created by QtCreator 2019-06-16T18:47:10
#
#-------------------------------------------------

QT       += core gui sql  charts designer quick
#QT       += core gui charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#include(../rasterwindow/rasterwindow.pri)
CONFIG += c++11

SOURCES += \
        analogclockwindow.cpp \
#    clock_analog.cpp \
    diagram_minut_form.cpp \
              main.cpp \
        mainwindow.cpp \
#        qwtanalogclock.cpp \
    sql_program_cl.cpp \
       ssgraphs.cpp \
    switch.cpp

HEADERS += \
#    AnalogClockWindow.h \
        analogclockwindow.h \
    diagram_minut_form.h \
            mainwindow.h \
#        qwt_dial.h \
#        qwt_dial_needle.h \
#        qwt_global.h \
#        qwtanalogclock.h \
#    qwtanalogclock.h \
    sql_program_cl.h \
          ssgraphs.h \
    style.h \
    switch.h

FORMS += \
        analogclockwindow.ui \
    diagram_minut_form.ui \
        mainwindow.ui \
#        qwtanalogclock.ui \
        ssgraphs.ui #\
#    temp_chart.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/Desktop/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#RESOURCES += \
#    resource.qrc

#SUBDIRS += \
#    contactlist/contactlist.pro

#DISTFILES += \
#    contactlist/ContactDelegate.ui.qml \
#    contactlist/ContactDialog.qml \
#    contactlist/ContactForm.ui.qml \
#    contactlist/ContactView.ui.qml \
#    contactlist/SectionDelegate.ui.qml \
#    contactlist/contactlist.qml \
#    contactlist/designer/Backend/ContactModel.qml \
#    contactlist/designer/Backend/qmldir \
#    contactlist/doc/images/qtquickcontrols2-contactlist.png \
#    contactlist/doc/src/qtquickcontrols2-contactlist.qdoc

RESOURCES += \
    s.qrc




