#-------------------------------------------------
#
# Project created by QtCreator 2013-04-17T23:07:30
#
#-------------------------------------------------

QT       += core gui quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Green
TEMPLATE = app

SOURCES += main.cpp \
    Image/ImageFile.cpp \
    Image/ImageFileDirectory.cpp

HEADERS  += \
    Image/ImageFile.h \
    Image/ImageFileDirectory.h

FORMS    +=

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    Dashboard.qml \
    ImagesList.qml
