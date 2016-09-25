#-------------------------------------------------
#
# Project created by QtCreator 2016-09-25T09:57:05
#
#-------------------------------------------------

QT       += core gui sql printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tsgui
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    forms/patientprofilewidget.cpp \
    forms/patientresearchslist.cpp \
    forms/patientslistwidget.cpp \
    forms/researchwidget.cpp \
    forms/startwidget.cpp \
    db/dbconnection.cpp

HEADERS  += mainwindow.h \
    forms/patientprofilewidget.h \
    forms/patientresearchslist.h \
    forms/patientslistwidget.h \
    forms/researchwidget.h \
    forms/startwidget.h \
    db/dbconnection.h

FORMS    += mainwindow.ui \
    forms/patientprofilewidget.ui \
    forms/patientresearchslist.ui \
    forms/patientslistwidget.ui \
    forms/researchwidget.ui \
    forms/startwidget.ui
