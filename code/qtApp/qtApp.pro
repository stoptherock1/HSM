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
    browseWindow.cpp \
    availableRoomsModel.cpp \
    staffPage.cpp \
    bookingPage.cpp \
    fistPage.cpp \
    roomAvailability.cpp \
    updateInformation.cpp

HEADERS  += \
    databaseConnection.h \
    loginWindow.h \
    browseWindow.h \
    hsmMetaData.h \
    availableRoomsModel.h \
    roomAvailability.h \
    bookingPage.h \
    staffPage.h \
    updateInformation.h \
    fistPage.h

FORMS    += \
    loginWindow.ui \
    browseWindow.ui \
    bookingPage.ui \
    fistPage.ui \
    roomAvailability.ui \
    staffPage.ui \
    updateInformation.ui

CONFIG += c++11

