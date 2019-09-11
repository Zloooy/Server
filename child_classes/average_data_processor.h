#ifndef AVERAGE_DATA_PROCESSOR_H
#define AVERAGE_DATA_PROCESSOR_H
#include <QString>
#include "base_classes/pipe.h"
class AverageDataProcessor: public Pipe<double, QString>
{ 
    double sum = 0;
    unsigned long int count = 0;
    void process(double) override;
    void clear() override;
};
#endif
