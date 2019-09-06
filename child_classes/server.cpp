#ifndef SERVER_CPP
#define SERVER_CPP
#include "server.h"
Server::Server(int port):
	port(port)
{}
Server::Server():
	Server(8081)
{}
void Server::run()
{
	int sock = socket(AF_INET, SOCK_DGRAM, 0), type_size = sizeof(double_bytes), num_bytes; 
        Server::double_bytes buf;
	struct sockaddr_in addr;
	if (sock < 0) throw "Cannot create socket";
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) throw "Can't bind socket";
        std::cout << "socket bound" << std::endl;
	while(isRunning())
	{
		num_bytes = recvfrom(sock, buf.bytes, type_size, 0, NULL, NULL); 
		if (num_bytes != type_size) throw "wrong byte count";
                std::cout << "net recieved " << buf.d << std::endl;
		send(buf.d);
	}
}
#endif
