#ifndef EXPECTED_VALUE_DATA_PROCESSOR_H
#define EXPECTED_VALUE_DATA_PROCESSOR_H
#include <QString>
#include <map>
#include "base_classes/pipe.h"
class ExpectedValueDataProcessor: public Pipe<double, QString>
{
    double count = 0;
    std::map<double, int> value_count;
    void process(double) override;
    public:
        void clear() override;
};
#endif
