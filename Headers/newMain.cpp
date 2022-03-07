#include <iostream>
#include "/Users/coderepublic1/Downloads/Nairi/Caesar/RabbitMQ/MyHANDL/chanell.h"


void myDeclareMethod(AMQP::Connection *connection)
{
    // create temporary channel to declare a queue
    AMQP::Channel channel(connection);

    // declare the queue (the channel object is destructed before the
    // instruction reaches the server, but the AMQP-CPP library can deal
    // with this)
    channel.declareQueue("my-new-queue");
}

int main(){
/*
Channel myChannel(&connection);
myChannel.declareQueue("my-queue");
myChannel.declareExchange("my-exchange");
lav tarberak chi qani vor arajiny fail linelu depqum
2rd el invalid kdarna
*/

Channel channel1(&connection);//tarber channalner unenalu depqum aveli apahov e linum
Channel channel2(&connection);
channel1.declareQueue("my-queue");
channel2.declareExchange("my-exchange");



}