######################################################################
# Automatically generated by qmake (3.1) Mon Aug 26 20:03:35 2019
######################################################################
QT += core network gui widgets testlib printsupport
TEMPLATE = app
TARGET = Server
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += qcustomplot.h \
           base_classes/background_service.h \
           base_classes/last_value_listener.h \
           base_classes/last_value_listener_background_service.h \
           base_classes/listener.h \
           base_classes/pipe.h \
           base_classes/queue_listener.h \
           base_classes/queue_listener_background_service.h \
           base_classes/sender.h \
           base_classes/sender_background_service.h \
           child_classes/main_window.h \
           child_classes/server.h \
           child_classes/graph_data_processor.h  \
           child_classes/graph.h \
           child_classes/test_server.h \
           child_classes/chart.h \
           child_classes/chart_data_processor.h 
SOURCES += main.cpp \
           qcustomplot.cpp \
           base_classes/background_service.cpp \
            child_classes/main_window.cpp \
           child_classes/server.cpp \
           child_classes/graph_data_processor.cpp \
           child_classes/graph.cpp \
           child_classes/chart_data_processor.cpp \
           child_classes/chart.cpp

