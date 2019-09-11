#include "expected_value_data_processor.h"
void ExpectedValueDataProcessor::process(double d)
{
    count++;
    value_count[d]++;
    double expected_value = 0;
    for (std::map<double, int>::iterator it = value_count.begin(); it != value_count.end(); it++)
    {
        expected_value += (it -> second / count) * //probability
        it -> first; //value
    }
    send("Математическое ожидание:\t" + QString::number(expected_value));
}
void ExpectedValueDataProcessor::clear()
{
    Pipe<double, QString>::clear();
    count = 0;
    std::map<double, int> empty;
    std::swap(empty, value_count);
}
