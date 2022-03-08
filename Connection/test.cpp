#include <iostream>
#include "/home/davit/Nairi/RabbitMQ/RabbitMQ/Githubex/AMQP-CPP/include/amqpcpp.h"
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
AMQP::SuccessCallback callb;
AMQP::Deferred def;
channel.declareExchange(exch, AMQP::fanout)
    .onSuccess([]() {
        std::cout<<"You succesfully declare exchange"<<std::endl;
    })

    .onError([](const char *message) {
        std::cout<<"something went wrong creating the exchange"<<std::endl;
        std::cout<<"  Error :"<<message<<std::endl;
    });

channel.declareQueue(que)
    .onSuccess([]() {
        std::cout<<"You succesfully declare Queue"<<std::endl;
    })

    .onError([](const char *message) {
        std::cout<<"something went wrong creating the exchange"<<std::endl;
        std::cout<<"  Error :"<<message<<std::endl;
    });
channel.bindQueue(exch, que,myrkey );
channel.publish(exch,myrkey,"Nairi");
channel.consume(que);
channel.close();

}
/*myChannel.onError([](const char *message) {

    // report error
    std::cout << "channel error: " << message << std::endl;
});

// install a generic callback that will be called when the channel is ready
// for sending the first instruction
myChannel.onReady([]() {

    // send the first instructions (like publishing messages)
});

yndhanur channel i hamar callback grelu dzev;
*/