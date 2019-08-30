#include "chart.h"
Chart::Chart(QWidget * parent):
    QCustomPlot(parent),
    ticker(new QCPAxisTickerText())
{
    chart = new QCPBars(xAxis, yAxis);
    xAxis -> setTicker(QSharedPointer<QCPAxisTickerText>(ticker));
}
void Chart::clear()
{
    LastValueListenerBackgroundService<chart_data>::clear();
    chart -> data() -> clear();
    replot();
}
void Chart::process(chart_data data)
{
        std::cout << "Chart replotting" << std::endl;
        QVector<double> x = QVector<double>::fromList(data.ticks.keys());
        std::cout << std::endl;
        QVectorIterator<double> it(x);
        while (it.hasNext()) std::cout << it.next() <<" ";
        std::cout << std::endl;
        chart -> setData(x,data.values);
        std::cout << "Data set" << std::endl;
        ticker -> setTicks(data.ticks);
        yAxis -> setRange(0, data.max_count);
        xAxis -> setRange(-1, x.size() + 1);
        std::cout << "Ticks set" << std::endl;
        replot();
}
