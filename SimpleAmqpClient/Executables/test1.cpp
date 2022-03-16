#include <iostream>
#include <cstdlib>
#include <src/SimpleAmqpClient/SimpleAmqpClient.h>
#include <Consumer/myConsumer.hpp>

using namespace AmqpClient;

int main(){
    std::string consumer_tag=connection->BasicConsume("N-queue","");
    Channel::OpenOpts opts = Channel::OpenOpts::FromUri("amqp://[guest[:guest]@]");
    Channel::ptr_t connection = Channel::Open(opts);

    while(true)
	{
		std::string msg;
	        Envelope::ptr_t env = connection->BasicConsumeMessage(consumer_tag);
    		connection->BasicAck(env->GetDeliveryInfo());
    		BasicMessage::ptr_t bodyBasicMessage=env->Message();
    		std::string message=bodyBasicMessage->Body();
    		std::cout<<"message -> "<<message<<std::endl;
		int count_of_msg = 100;
		bool flag = connection->BasicConsumeMessage(count_of_msg);
		if (flag == false){
			std::cout <<"timeout"<<std::endl;
			break;
		}
	}

}
