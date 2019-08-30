#ifndef GRAPH_DATA_PROCESSOR
#define GRAPH_DATA_PROCESSOR
#include <QVector>
#include "base_classes/pipe.h"
typedef struct{
    double min_y = 0, max_y = 0, max_x = 0, x, y;
} graph_data;
class GraphDataProcessor: public Pipe<double, graph_data>
{
    double max_y = 0;
    double min_y = 0;
    double max_x = 0;
    void process(double) override;
    public:
        void clear() override;
};
#endif
