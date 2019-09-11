#ifndef SQUARE_DEVIATION_DATA_PROCESSOR_H
#define SQUARE_DEVIATION_DATA_PROCESSOR_H
#include <QString>
#include <cmath>
#include "base_classes/pipe.h"
class SquareDeviationDataProcessor: public Pipe<double, QString>
{
    std::vector<double> numbers;
    double sum = 0;
    int count = 0;
    void process(double) override;
    void clear() override;
};
#endif
