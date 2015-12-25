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
    availableRoomsModel.cpp \
    staffPage.cpp \
    roomAvailability.cpp \
    updateInformation.cpp \
    firstPage.cpp \
    bookingDialog.cpp \
    availableRoomsBrowserDialog.cpp

HEADERS  += \
    databaseConnection.h \
    loginWindow.h \
    hsmMetaData.h \
    availableRoomsModel.h \
    roomAvailability.h \
    staffPage.h \
    updateInformation.h \
    firstPage.h \
    bookingDialog.h \
    availableRoomsBrowserDialog.h

FORMS    += \
    loginWindow.ui \
    roomAvailability.ui \
    staffPage.ui \
    updateInformation.ui \
    firstPage.ui \
    bookingDialog.ui \
    availableRoomsBrowserDialog.ui

CONFIG += c++11

