#-------------------------------------------------
#
# Project created by QtCreator 2015-12-04T10:25:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HMS
TEMPLATE = app


SOURCES += main.cpp\
        fistpage.cpp \
    roomavailability.cpp \
    staffpage.cpp \
    bookingpage.cpp \
    updateinformation.cpp

HEADERS  += fistpage.h \
    roomavailability.h \
    staffpage.h \
    bookingpage.h \
    updateinformation.h

FORMS    += fistpage.ui \
    roomavailability.ui \
    staffpage.ui \
    bookingpage.ui \
    updateinformation.ui
