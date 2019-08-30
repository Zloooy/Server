#include "graph_data_processor.h"
void GraphDataProcessor::process(double y)
{
    max_y = ((y - max_y) > 0) ? y : max_y;
    min_y = ((y - min_y) < 0) ? y : min_y;
    max_x++;
    Pipe<double, graph_data>::send({min_y, max_y, max_x, max_x, y});
}
void GraphDataProcessor::clear()
{
    Pipe<double, graph_data>::clear();
    min_y = 0;
    max_y = 0;
    max_x = 0;
}
