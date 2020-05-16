TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    inode.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    inode.h

