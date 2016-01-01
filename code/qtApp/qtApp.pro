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
    availableRoomsModel.cpp \
    staffPage.cpp \
    roomAvailability.cpp \
    updateInformation.cpp \
    bookingDialog.cpp \
    loginDialog.cpp \
    availableRoomsWindow.cpp \
    reservationsDialog.cpp
    reservationModel.cpp \
    roomModel.cpp \
    staffModel.cpp

HEADERS  += \
    databaseConnection.h \
    hsmMetaData.h \
    availableRoomsModel.h \
    roomAvailability.h \
    staffPage.h \
    updateInformation.h \
    bookingDialog.h \
    loginDialog.h \
    availableRoomsWindow.h \
    reservationsDialog.h
    reservationModel.h \
    roomModel.h \
    staffModel.h

FORMS    += \
    roomAvailability.ui \
    staffPage.ui \
    updateInformation.ui \
    bookingDialog.ui \
    loginDialog.ui \
    availableRoomsWindow.ui \
    reservationsDialog.ui

CONFIG += c++11

