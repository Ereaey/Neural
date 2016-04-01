#-------------------------------------------------
#
# Project created by QtCreator 2016-03-31T14:46:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Neural
TEMPLATE = app

INCLUDEPATH += /home/eray/boost
LIBS += "-L/home/eray/boost/libs"

SOURCES += main.cpp\
        mainwindow.cpp \
    idealnerve.cpp \
    qcustomplot.cpp \
    data.cpp

HEADERS  += mainwindow.h \
    idealnerve.h \
    qcustomplot.h \
    data.h

FORMS    += mainwindow.ui
