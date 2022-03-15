#include <iostream>
#include <cstdlib>  
#include <string>   
#include "src/SimpleAmqpClient.h"
#include <Publisher/myPublisher.hpp>


int main()
{
    char *sz_brok = std::getenv("AMQP_BROKER");
    AmqpClient::Channel::ptr_t channel;
    if (sz_brok != nullptr)
        channel = AmqpClient::Channel::Create(sz_brok);
    else
        channel = AmqpClient::Channel::Create("127.0.0.1", 5672,"guest","guest"); 

    std::string msg="message";
    std::shared_ptr<AmqpClient::Publisher>publisher = AmqpClient::Publisher::Create(channel,"Nairi");
    int count_of_msg = 100;
    for(int i{};i < count_of_msg;++i)
        publisher->publish(msg + '<'+std::to_string(i)+'>');
        
}