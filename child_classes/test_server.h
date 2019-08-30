#ifndef TEST_SERVER_CPP
#define TEST_SERVER_CPP
#include <random>
#include <unistd.h>
class TestServer: public SenderBackgroundService<double> 
{
void run() override;
};
void TestServer::run()
{
	std::uniform_real_distribution<double> uni(0, 1000);
	std::default_random_engine re;
	while(isRunning())
	{
		sleep(1);
		send(uni(re));
	}
}
#endif
