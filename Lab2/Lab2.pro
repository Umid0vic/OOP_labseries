TEMPLATE = app
CONFIG += c++11
QT += core gui widgets

INCLUDEPATH += C:\Users\Dell\Documents\School\Obj_Oriented\Labb_2\shape-lib-incomplete\incomplete\headers

LIBS += C:\Users\Dell\Documents\School\Obj_Oriented\Labb_2\shape-lib-incomplete\incomplete\shape-lib_mingw-32_qt-5-14-1_debug.a

SOURCES += main.cpp \
    circle.cpp \
    cross.cpp \
    point.cpp \
    square.cpp

HEADERS += \
    circle.h \
    cross.h \
    point.h \
    square.h
