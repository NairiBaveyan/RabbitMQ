#include <iostream>
#include <cstdlib>
#include "../src/SimpleAmqpClient.h"
#include "../Consumer/myConsumer.hpp"
#include <string>



using namespace AmqpClient;

int main(){

    Channel::OpenOpts opts = Channel::OpenOpts::FromUri("amqp://[guest[:guest]@]");
    Channel::ptr_t connection = Channel::Open(opts);
    Consumer myCons(connection,"NairiEX");
	int count_of_msg = 100;
    while(count_of_msg--)
	{
		std::string msg;
    	std::cout<<"message -> "<<myCons.waitForStrMsg()<<std::endl;
	}

}

