#ifndef SERVER_H
#define SERVER_H
#include "base_classes/sender_background_service.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
class Server: public SenderBackgroundService<double>
{
        typedef union {
            double d;
            char bytes[sizeof(double)];
        } double_bytes;
	int port = 8081;
	void run() override;
	public:
		Server(int);
		Server();
};
#endif
