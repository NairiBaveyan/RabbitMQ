#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include <string>

using namespace AmqpClient;

//myTest


int main()
{
    Channel::ptr_t connection = Channel::Create("127.0.0.1",5672,"guest","guest");
    const std::string body("message");
    BasicMessage::ptr_t out_message = BasicMessage::Create(body);
    connection->BasicPublish("N-exchange", "N-key",BasicMessage::Create("Message1"));
    std::string consumer_tag=connection->BasicConsume("N-queue","");
Envelope::ptr_t env = connection->BasicConsumeMessage(cons_tag);
        connection->BasicAck(env->GetDeliveryInfo());
        BasicMessage::ptr_t bodyBasicMessage=env->Message();
        std::string message=bodyBasicMessage->Body();
        std::cout<<"message -> "<<message<<std::endl;
}