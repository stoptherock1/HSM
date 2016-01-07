#-------------------------------------------------
#
# Project created by QtCreator 2015-11-12T12:36:50
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtApp
TEMPLATE = app


CONFIG += c++11

FORMS += \
    availableRoomsWindow.ui \
    bookingDialog.ui \
    loginDialog.ui \
    reservationsDialog.ui \
    roomavailability.ui \
    staffPage.ui \
    updateInformation.ui

HEADERS += \
    availableRoomsModel.h \
    availableRoomsWindow.h \
    bookingDialog.h \
    databaseConnection.h \
    hsmMetaData.h \
    loginDialog.h \
    reservationModel.h \
    reservationsDialog.h \
    roomavailability.h \
    roomModel.h \
    staffModel.h \
    staffPage.h \
    updateInformation.h

SOURCES += \
    availableRoomsModel.cpp \
    availableRoomsWindow.cpp \
    bookingDialog.cpp \
    databaseConnection.cpp \
    loginDialog.cpp \
    main.cpp \
    reservationModel.cpp \
    reservationsDialog.cpp \
    roomAvailability.cpp \
    roomModel.cpp \
    staffModel.cpp \
    staffpage.cpp \
    updateInformation.cpp

