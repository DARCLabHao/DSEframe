#-------------------------------------------------
#
# Project created by QtCreator 2017-12-03T22:14:11
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport concurrent

TARGET = QT_DSE_1_1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    newfile.cpp \
    aboutwindow.cpp \
    mycheckbox.cpp \
    helpwindow.cpp

HEADERS += \
        mainwindow.h \
    qcustomplot.h \
    newfile.h \
    aboutwindow.h \
    mycheckbox.h \
    helpwindow.h

FORMS += \
        mainwindow.ui \
    newfile.ui \
    aboutwindow.ui \
    helpwindow.ui
