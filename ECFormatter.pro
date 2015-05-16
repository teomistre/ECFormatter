#-------------------------------------------------
#
# Project created by QtCreator 2015-05-09T15:10:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ECFormatter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    filepool.cpp \
    zipper.cpp \
    zippedbuffer.cpp \
    zippedbufferpool.cpp

HEADERS += \
    filepool.h \
    zipper.h \
    zippedbuffer.h \
    zippedbufferpool.h
