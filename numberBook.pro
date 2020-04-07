#-------------------------------------------------
#
# Project created by QtCreator 2020-04-04T18:44:53
#
#-------------------------------------------------

QT       += core gui\
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = numberBook
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    person.cpp \
    dbhelper.cpp

HEADERS  += mainwindow.h \
    person.h \
    dbhelper.h

FORMS    += mainwindow.ui
