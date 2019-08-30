#ifndef CHART_H
#define CHART_H
#include "qcustomplot.h"
#include "base_classes/last_value_listener_background_service.h"
#include "chart_data_processor.h"
class Chart: public QCustomPlot, public LastValueListenerBackgroundService<chart_data>
{
    QCPBars * chart;
    QCPAxisTickerText * ticker;
    void process(chart_data) override;
    public:
    void clear() override;
    Chart(QWidget * parent = Q_NULLPTR);
};
#endif
