#include <iostream>
#include "/usr/local/Cellar/amqp-cpp/4.3.16/include/amqpcpp.h"
#include "MyConnectionHandler.h"

int main()
{  

// create an instance of your own connection handler
MyConnectionHandler myHandler;

// create a AMQP connection object
AMQP::Connection connection(&myHandler, AMQP::Login("guest","guest"), "/");

// and create a channel
AMQP::Channel channel(&connection);

// use the channel object to call the AMQP method you like
std::string exch{"Nairis-exchange"},que{"Nairis-queue"},myrkey{"Nairis-routing-key"};
channel.declareExchange(exch, AMQP::fanout);
channel.declareQueue(que);
channel.bindQueue(exch, que,myrkey );
channel.publish(exch,myrkey,"Nairi");
channel.consume(que);
channel.close();

}
