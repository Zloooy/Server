#ifndef LED_DATA_PROCESSOR_H
#define LED_DATA_PROCESSOR_H
#include "base_classes/pipe.h"
template <int delay_time>
class LedDataProcessor: public Pipe<double, bool>
{
    std::chrono::milliseconds delay = std::chrono::milliseconds(0);
    std::thread * timer_thread = NULL;
    void process(double) override;
};
template <int delay_time>
void LedDataProcessor<delay_time>::process(double d)
{
    send(true);
    delay = std::chrono::milliseconds(delay_time);
    if (timer_thread == NULL)
    {
        timer_thread = new std::thread([this](){
            while(this -> delay > std::chrono::milliseconds(0))
            {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            this -> delay -= std::chrono::milliseconds(100);
            }
            send(false);
            delete this -> timer_thread;
            this -> timer_thread = NULL;
            });
        timer_thread -> detach();
    }
}
#endif
