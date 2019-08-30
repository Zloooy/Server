#ifndef CHART_DATA_PROCESSOR_H
#define CHART_DATA_PROCESSOR_H
#include "base_classes/pipe.h"
#include "qcustomplot.h"
typedef struct {
    QVector<double> values;
    QMap< double, QString> ticks;
    double max_count;
} chart_data;
class ChartDataProcessor: public Pipe<double, chart_data>, public QCustomPlot
{
    QVector<double> range_borders;
    chart_data data2send;
    void process(double);
    public:
    ChartDataProcessor();
    void clear() override;
};
#endif
