#include "child_classes/graph.h"
Graph::Graph(QWidget * parent):
    QCustomPlot(parent)
{
    setInteractions(QCP::iSelectPlottables);
    setSelectionRectMode(QCP::srmSelect);
    graphic = QCustomPlot::addGraph();
    graphic -> setPen(QColor(50, 50, 255, 255));
    graphic -> setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    graphic -> setAdaptiveSampling(true);
    graphic -> setSelectable(QCP::stDataRange);
    QCustomPlot::xAxis -> setRange(0, 100);
    QCustomPlot::replot();
    QObject::connect(graphic, qOverload<bool>(&QCPGraph::selectionChanged), this, &Graph::selection_changed);
    QObject::connect(animTimer, &QTimer::timeout, this, &Graph::redraw);
    animTimer -> start(50);
}
void Graph::clear()
{
    std::cout << "clearing graph" << std::endl;
    QueueListener<graph_data>::clear();
    graphic -> data() -> clear();
    replot();
    std::cout << "grsph cleared" << std::endl;
}
void Graph::redraw()
{
    static int i = 0;
    if (!msg_queue.empty())
    {
        std::cout <<"graph replotting" << std::endl;
        while (!(msg_queue.size() == 1))
        {
            std::cout << "adding " << msg_queue.front().x << " " << msg_queue.front().y << std::endl;
            graphic -> addData(msg_queue.front().x, msg_queue.front().y);
            msg_queue.pop();
            graphic -> addData(i,i*i);
            i++;
        QCustomPlot::replot();
        }         
        graphic -> addData(msg_queue.front().x, msg_queue.front().y);
        QCustomPlot::yAxis -> setRange(msg_queue.front().min_y, msg_queue.front().max_y);
        QCustomPlot::xAxis -> setRange(0, msg_queue.front().max_x);
        msg_queue.pop();
        QCustomPlot::replot();
    }
    animTimer -> start(50);
}
void Graph::selection_changed(bool selected)
{
    if (selected)
    {
        QCPDataRange range = graphic -> selection().dataRange(0);
        selected_range(range.begin(), range.end());
    }
}
