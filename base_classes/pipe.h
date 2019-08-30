#ifndef PIPE_H
#define PIPE_H
#include "sender.h"
#include "queue_listener_background_service.h"
template <typename frommsgtype, typename tomsgtype>
class Pipe: public QueueListenerBackgroundService<frommsgtype>, public Sender<tomsgtype>
{
	public:
		void clear();
};
template <typename frommsgtype, typename tomsgtype>
void Pipe<frommsgtype, tomsgtype>::clear()
{
	Sender<tomsgtype>::clear_listeners();
}
#endif
