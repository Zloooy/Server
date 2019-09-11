#include "child_classes/data_buffer.h"
void DataBuffer::recieve(double d)
{
    all_data.push_back(d);
}
void DataBuffer::clear()
{
    std::vector<double> empty;
    std::swap(empty, all_data);
}
void DataBuffer::emit_all_data()
{
    clear_listeners();
    for (std::vector<double>::iterator it = all_data.begin(); it != all_data.end(); it++)
    {
        send(*it);
    }
}
void DataBuffer::emit_data_range(int begin, int end)
{
    clear_listeners();
    for (int i = begin; i < end; i++)
    {
        send(all_data[i]);
    }
}
