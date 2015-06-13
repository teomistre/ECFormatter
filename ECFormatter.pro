#-------------------------------------------------
#
# Project created by QtCreator 2015-05-09T15:10:51
#
#-------------------------------------------------

QT       += core

QT       -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = ECFormatter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    filepool.cpp \
    zipper.cpp \
    zippedbuffer.cpp \
    zippedbufferpool.cpp \
    writer.cpp \
    epsifilecompressor.cpp \
    unzipper.cpp \
    tabwidget.cpp

HEADERS += \
    filepool.h \
    zipper.h \
    zippedbuffer.h \
    zippedbufferpool.h \
    writer.h \
    epsifilecompressor.h \
    unzipper.h \
    tabwidget.h

FORMS += \
    tabwidget.ui
