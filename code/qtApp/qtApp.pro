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
    bookingpage.cpp \
    fistpage.cpp \
    roomavailability.cpp \
    simpleClass.cpp \
    staffpage.cpp \
    updateinformation.cpp

HEADERS  += \
    databaseConnection.h \
    loginWindow.h \
    browseWindow.h \
    hsmMetaData.h \
    availableRoomsModel.h \
    bookingpage.h \
    fistpage.h \
    roomavailability.h \
    simpleClass.h \
    staffpage.h \
    updateinformation.h

FORMS    += \
    loginWindow.ui \
    browseWindow.ui \
    bookingpage.ui \
    fistpage.ui \
    roomavailability.ui \
    staffpage.ui \
    updateinformation.ui

CONFIG += c++11

