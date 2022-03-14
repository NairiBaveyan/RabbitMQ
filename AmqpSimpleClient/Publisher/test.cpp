#include <iostream>
#include <stdlib.h>     /* getenv */
#include "SimpleAmqpClient.h"
#include "myPublisher.hpp"


int main()
{
    char *sz_brok = getenv("AMQP_BROKER");
    AmqpClient::Channel::ptr_t channel;
    if (sz_brok != NULL)
        channel = AmqpClient::Channel::Create(sz_brok);
    else
        channel = AmqpClient::Channel::Create("127.0.0.1", 5672,"guest","guest"); //"192.168.66.1"

    std::string msg="hello Nairi";
    std::shared_ptr<AmqpClient::Publisher>publisher = AmqpClient::Publisher::Create(channel,"Nairi");
    publisher->publish(msg);
}