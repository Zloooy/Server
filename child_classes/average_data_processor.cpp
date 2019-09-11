#include "child_classes/average_data_processor.h"
void AverageDataProcessor::process(double d)
{
    sum += d;
    count++;
    double average = sum/count;
    send("Среднее арифметическое:\t"+QString::number(average));
}
void AverageDataProcessor::clear()
{
    sum = 0;
    count = 0;
    Pipe<double, QString>::clear();
}
