#include <iostream>
#include <stdlib.h>
#include "SimpleAmqpClient.h"
#include "myConsumer.hpp"

using namespace AmqpClient;

int main(){
    char *szBroker = getenv("AMQP_BROKER");
    Channel::ptr_t channel;
    if (szBroker != NULL)
        channel = Channel::Create(szBroker);
    else
        channel = Channel::Create("192.168.66.1", 5672);

    std::shared_ptr<Consumer> consum = Consumer::Create(channel,"exch");


    while(true)
	{
		std::string msg;
		//  a= pub.WaitForMessageString(5000);

		Envelope::ptr_t env;
		bool flag = channel->BasicConsumeMessage("SimpleSubscriber_", env, 7000);
		if (flag == false){
			std::cout <<"timeout"<<std::endl;
			break;
		}

		msg = env->Message()->Body();

		std::cout<<msg<<std::endl;
		
	}

}