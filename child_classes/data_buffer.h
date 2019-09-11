#ifndef DATA_BUFFER_H
#define DATA_BUFFER_H
#include <vector>
#include "base_classes/listener.h"
#include "base_classes/sender.h"
class DataBuffer: public Listener<double>, public Sender<double>
{
    std::vector<double> all_data;
    public:
        void recieve(double) override;
        void clear() override;
        void emit_all_data();
        void emit_data_range(int, int);
};
#endif
