#include "square_deviation_data_processor.h"
void SquareDeviationDataProcessor::process(double d)
{
    double sqdev;
    numbers.push_back(d);
    sum += d;
    std::cout << "sddp: sum=" << sum <<std::endl;
    count++;
    if (count == 1)
    {
        sqdev = 0;
    }
    else
    {
        double average = sum/count, sqsum = 0;
        std::cout << "average: " << average <<std::endl;
        std::vector<double>::iterator it = numbers.begin();
        for (; it != numbers.end(); it++)
        {
            sqsum += ((*it) - average) * ((*it) - average);
        }
        sqdev = sqrt(sqsum / (count - 1));
    }
    std::cout << "sending sqdev" << std::endl;
    send("СКО:\t" + QString::number(sqdev));
}
void SquareDeviationDataProcessor::clear()
{
    Pipe<double, QString>::clear();
    sum = 0;
    count = 0;
    std::vector<double> empty; 
    std::swap(empty, numbers);
}
