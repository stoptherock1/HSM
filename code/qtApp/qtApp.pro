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
    BrowseWindow.cpp \
    databaseConnection.cpp

HEADERS  += \
    BrowseWindow.h \
    databaseConnection.h

FORMS    += \
    BrowseWindow.ui

CONFIG += c++11
