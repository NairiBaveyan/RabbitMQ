#include "../src/SimpleAmqpClient.h"
#include "../Publisher/MyPublisher.hpp"
#include "../Consumer/myConsumer.hpp"
#include <iostream>
#include <string>

using namespace AmqpClient;

//myTest


int main()
{
    
    
    
    
    
    
    
    
    

    
    
    //Channel::OpenOpts opts  = Channel::OpenOpts();
    Channel::OpenOpts opts = Channel::OpenOpts::FromUri("amqp://[guest[:guest]@]");
    Channel::ptr_t connection = Channel::Open(opts);
    Publisher myPub(connection,"NairiEX");
    myPub.publish("Hello");
    Consumer myCons(connection,myPub.getExchangeName());
    std::cout<<myCons.waitForStrMsg()<<std::endl;
    /*const std::string body("message");
    BasicMessage::ptr_t out_message = BasicMessage::Create(body);
    connection->BasicPublish("N-exchange", "N-key",BasicMessage::Create("Message1"));
    std::string consumer_tag=connection->BasicConsume("N-queue","");
    Envelope::ptr_t env = connection->BasicConsumeMessage(consumer_tag);
    connection->BasicAck(env->GetDeliveryInfo());
    BasicMessage::ptr_t bodyBasicMessage=env->Message();
    std::string message=bodyBasicMessage->Body();
    std::cout<<"message -> "<<message<<std::endl;
    */
}
