#ifndef LAST_VALUE_LISTENER_H
#define LAST_VALUE_LISTENER_H
#include "listener.h"
#include <iostream>
template <typename msgtype>
class LastValueListener: public Listener<msgtype>
{
	protected:
	msgtype * last_value = nullptr;
	public:
        ~LastValueListener();
	void recieve(msgtype) override; 
	void clear() override;
};
template<typename msgtype>
void LastValueListener<msgtype>::recieve(msgtype msg)
{
    //std::cout << "lvl recieving " << std::endl;
    if (last_value != nullptr) delete last_value;
    last_value = new msgtype(msg);
}
template<typename msgtype>
void LastValueListener<msgtype>::clear()
{
	if (last_value != nullptr) delete last_value;
	last_value = nullptr;
}
template<typename msgtype>
LastValueListener<msgtype>::~LastValueListener()
{
    if (last_value != nullptr) delete last_value;
    delete last_value;
}
#endif
