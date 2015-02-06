#-------------------------------------------------
#
# Project created by QtCreator 2015-02-05T22:45:56
#
#-------------------------------------------------

QT       += core
QT       += serialport
QT       -= gui

TARGET = BBBArduinoController
    target.files = BBBArduinoController
    target.path = /home/tb/uart
INSTALLS += target

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
SOURCES += main.cpp
