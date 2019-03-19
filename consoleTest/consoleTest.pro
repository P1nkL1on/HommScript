QT += core
QT -= gui

TARGET = consoleTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    memoryholder.cpp \
    crpointer.cpp \
    crobject.cpp \
    crset.cpp

HEADERS += \
    memoryholder.h \
    memoryarray.h \
    memorystoragetype.h \
    crpointer.h \
    crobject.h \
    crset.h \
    crvaluetypes.h

