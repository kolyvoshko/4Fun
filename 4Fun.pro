TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11
QMAKE_CXXFLAGS += -Wall -Wextra -std=c++11

SOURCES += main.cpp \
    taimer.cpp \
    multithread/threadpool.cpp \
    multithread/worker.cpp \
    container/linked_list.cpp

HEADERS += \
    taimer.h \
    patern/singleton.h \
    algorithm/find_max.h \
    virtual_inheritance.h \
    multithread/threadpool.h \
    multithread/worker.h \
    algorithm/find_max.h \
    patern/singleton.h \
    container/linked_list.h

