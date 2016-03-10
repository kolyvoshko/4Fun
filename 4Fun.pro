TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11
QMAKE_CXXFLAGS += -Wall -Wextra -std=c++11

SOURCES += main.cpp \
    taimer.cpp \
    multithread/threadpool.cpp \
    multithread/worker.cpp

HEADERS += \
    taimer.h \
    singleton.h \
    find_max.h \
    virtual_inheritance.h \
    multithread/threadpool.h \
    multithread/worker.h

