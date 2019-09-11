#ifndef MIN_MAX_DATA_PROCESSSOR_H
#define MIN_MAX_DATA_PROCESSSOR_H
#include "base_classes/pipe.h"
#include <QString>
class MinMaxDataProcessor: public Pipe<double, QString>
{
    double * min = nullptr, * max = nullptr;
    void process(double) override;
    public:
        void clear() override;
};
#endif
