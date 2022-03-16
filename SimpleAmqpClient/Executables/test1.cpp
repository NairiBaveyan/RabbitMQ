#include <iostream>
#include <cstdlib>
#include <src/SimpleAmqpClient/SimpleAmqpClient.h>
#include <Consumer/myConsumer.hpp>

using namespace AmqpClient;

int main(){
    const char *env_p = std::getenv("AMQP_BROKER");
    Channel::ptr_t channel;
    if (env_p)
        channel = Channel::Create(env_p);
    else
        channel = Channel::Create("127.0.0.1", 5672);

    std::shared_ptr<Consumer> consum = Consumer::Create(channel,"exch");


    while(true)
	{
		std::string msg;
		Envelope::ptr_t env;
		int count_of_msg = 100;
		bool flag = channel->BasicConsumeMessage("SimpleSubscriber_", env, count_of_msg);
		if (flag == false){
			std::cout <<"timeout"<<std::endl;
			break;
		}

		msg = env->Message()->Body();

		std::cout<<msg<<std::endl;
		
	}

}
