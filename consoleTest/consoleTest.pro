QT += core
QT -= gui

TARGET = consoleTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    memoryholder.cpp

HEADERS += \
    memoryholder.h \
    memoryarray.h

