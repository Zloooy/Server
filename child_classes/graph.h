#ifndef GRAPH_H
#define GRAPH_H
#include "base_classes/queue_listener.h"
#include "child_classes/graph_data_processor.h"
#include "qcustomplot.h"
#include <iostream>
class Graph: public QCustomPlot, public QueueListener<graph_data>
{
    Q_OBJECT
    void redraw();
    QCPGraph * graphic;
    QTimer * animTimer = new QTimer(this);
    public: 
        Graph(QWidget * parent = Q_NULLPTR);
        void clear() override;
    signals:
        void selected_range(int, int);
    public slots:
        void selection_changed(bool);
};
#endif
