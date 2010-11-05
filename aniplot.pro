#-------------------------------------------------
#
# Project created by QtCreator 2010-10-22T22:05:24
#
#-------------------------------------------------

QT       += core gui phonon

TARGET = aniplot
TEMPLATE = app


SOURCES += main.cpp\
        aniwindow.cpp \
    event.cpp \
    aniscene.cpp \
    neweventdialog.cpp \
    screenshotsave.cpp \
    screenshotselectorborder.cpp \
    resizehandle.cpp

HEADERS  += aniwindow.h \
    event.h \
    aniscene.h \
    neweventdialog.h \
    screenshotsave.h \
    screenshotselectorborder.h \
    resizehandle.h

FORMS    += aniwindow.ui \
    neweventdialog.ui \
    screenshotsave.ui

RESOURCES += \
    reso.qrc
