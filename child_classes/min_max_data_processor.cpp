#include "min_max_data_processor.h"
void MinMaxDataProcessor::process(double d)
{
    std::cout << "min_max_dp: processing" << std::endl;
    if (min == nullptr)
    {
        min = new double(d);
        max = new double(d);
    }
    else
    {
        if ((d - *min) < 0) min = new double(d);
        else if ((d - *max) > 0) max = new double(d);
    }
    send("Минимум:\t"+QString::number(*min)+"\nМаксимум:\t"+QString::number(*max));
}
void MinMaxDataProcessor::clear()
{
    Pipe<double, QString>::clear();
    if (min != nullptr)
    {
        delete min;
        delete max;
        min = nullptr;
        max = nullptr;
    }
}
