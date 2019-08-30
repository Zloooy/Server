#include "chart_data_processor.h"
ChartDataProcessor::ChartDataProcessor()
{
    range_borders << 100 << 200 << 500 << 900;
    data2send.values.reserve(range_borders.size() + 1);
    data2send.values.resize(range_borders.size() + 1);
    data2send.values.fill(0);
    QVectorIterator<double> it(range_borders);
    double previous = it.next();
    int i = 1;
    data2send.ticks.insert(i, "<"+QString::number(previous));
    i++;
    while(it.hasNext())
    {
        double current = it.next();
        data2send.ticks.insert(i, QString::number(previous)+"-"+QString::number(current));
        previous = current;
        i++;
    }
    data2send.ticks.insert(i, ">"+QString::number(previous));
}
void ChartDataProcessor::process(double d)
{
    std::cout << "start chart processing" << std::endl;
    QVectorIterator<double> it(range_borders);
    int i = 0;
    while(it.hasNext())
    {
        double it_val = it.next();
        if (d < it_val)
        {
            std::cout << d <<" < " <<it_val <<std::endl;
            data2send.values[i]++;
            data2send.max_count = data2send.max_count > data2send.values[i] ? data2send.max_count:data2send.values[i];
            std::cout << "ended chart processing" << std::endl;
            send(data2send);
            return;
        }
            i++;
    }
    std::cout << d << " > " << range_borders.end();
    data2send.values[i]++;
    data2send.max_count = data2send.max_count > data2send.values[i] ? data2send.max_count:data2send.values[i];
    std::cout << "ended chart processing" << std::endl;
    send(data2send);
}
void ChartDataProcessor::clear()
{
    std::cout << "clearing chart dp" << std::endl;
    data2send.values.fill(0);
    data2send.max_count = 0;
    Pipe<double, chart_data>::clear();
}
