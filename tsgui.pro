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
        db/dbconnection.cpp \
        device/ADCDataReader.cpp \
        device/calibrator.cpp \
        device/datahoarder.cpp \
        device/ioton.cpp \
        device/main.cpp \
        device/signalconverter.cpp \
        device/temperatureparameerscalulator.cpp \
        device/analyze/signalanalyzer.cpp \
        device/analyze/volumevaluescalc.cpp \
        qcustomplot.cpp

HEADERS  += mainwindow.h \
        forms/patientprofilewidget.h \
        forms/patientresearchslist.h \
        forms/patientslistwidget.h \
        forms/researchwidget.h \
        forms/startwidget.h \
        db/dbconnection.h \
        device/ADCDataReader.h \
        device/calibrator.h \
        device/datahoarder.h \
        device/datatypes.h \
        device/ioton.h \
        device/Rtusbapi.h \
        device/signalconverter.h \
        device/temperatureparameerscalulator.h \
        device/analyze/signalanalyzer.h \
        device/analyze/volumevaluescalc.h \
        qcustomplot.h

FORMS    += mainwindow.ui \
        forms/patientprofilewidget.ui \
        forms/patientresearchslist.ui \
        forms/patientslistwidget.ui \
        forms/researchwidget.ui \
        forms/startwidget.ui

win32: LIBS += -L$$PWD/device/lib/ -lRtusbapi

INCLUDEPATH += $$PWD/device
DEPENDPATH += $$PWD/device

CONFIG += c++14

