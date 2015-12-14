#-------------------------------------------------
#
# Project created by QtCreator 2015-11-12T12:36:50
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtApp
TEMPLATE = app


SOURCES += main.cpp\
    databaseConnection.cpp \
    loginWindow.cpp \
    browseWindow.cpp

HEADERS  += \
    databaseConnection.h \
    loginWindow.h \
    browseWindow.h \
    hsmMetaData.h

FORMS    += \
    loginWindow.ui \
    browseWindow.ui

CONFIG += c++11

