#ifndef LAST_VALUE_LISTENER_BACKGROUND_SERVICE_H
#define LAST_VALUE_LISTENER_BACKGROUND_SERVICE_H
#include "background_service.h"
#include "last_value_listener.h"
#include<condition_variable>
#include <iostream>
template<typename msgtype>
class LastValueListenerBackgroundService: public LastValueListener<msgtype>, public BackgroundService
{
    std::condition_variable wait4data;
    std::atomic<bool> data_ready = ATOMIC_VAR_INIT(false);
    void run() override;
    public:
    void recieve(msgtype) override;
    void clear() override;
    protected:
    virtual void process(msgtype) = 0;
};
template<typename msgtype>
void LastValueListenerBackgroundService<msgtype>::recieve(msgtype msg)
{
    LastValueListener<msgtype>::recieve(msg);
    data_ready = ATOMIC_VAR_INIT(true);
    wait4data.notify_one();
}
template<typename msgtype>
void LastValueListenerBackgroundService<msgtype>::run()
{
    while (isRunning())
    {
	std::cout << "running" << std::endl;
        std::mutex m;
        std::unique_lock<std::mutex> lock(m);
	while (!data_ready) wait4data.wait(lock);
        data_ready = ATOMIC_VAR_INIT(false);
        process(*LastValueListener<msgtype>::last_value);
    }
}
template<typename msgtype>
void LastValueListenerBackgroundService<msgtype>::clear()
{	
	data_ready = ATOMIC_VAR_INIT(false);
	LastValueListener<msgtype>::clear();
}
#endif
