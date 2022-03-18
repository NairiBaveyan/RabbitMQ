
#include "/home/ashot/Downloads/RRR/sslh/ssl.h"
#include "/home/ashot/Downloads/RRR/sslh/base.h"
#include "/home/ashot/Downloads/RRR/AMQP-CPP/include/amqpcpp.h"
#include "/home/ashot/Downloads/RRR/AMQP-CPP/include/amqpcpp/linux_tcp.h"
#include <ev.h>
#include <amqpcpp.h>
#include <amqpcpp/libev.h>
#include "myTcpH.h"


int main()
{

	// create an instance of your own tcp handler
MyTcpHandler myHandler;

// address of the serv
AMQP::Address address("amqp://guest:guest@localhost/vhost");

// create a AMQP connection object
AMQP::TcpConnection connection(&myHandler, address);

// and create a channel
AMQP::TcpChannel channel(&connection);

// use the channel object to call the AMQP method you like
channel.declareExchange("my-exchange", AMQP::fanout);
channel.declareQueue("my-queue");
channel.bindQueue("my-exchange", "my-queue", "my-routing-key");
/*
    // access to the event loop
    auto *loop = EV_DEFAULT;

    // handler for libev (so we don't have to implement AMQP::TcpHandler!)
    AMQP::LibEvHandler handler(loop);

    // make a connection
    AMQP::TcpConnection connection(&handler, AMQP::Address("amqp://localhost/"));

    // we need a channel too
    AMQP::TcpChannel channel(&connection);

    // create a temporary queue
    channel.declareQueue(AMQP::exclusive).onSuccess([&connection](const std::string &name, uint32_t messagecount, uint32_t consumercount) {
        // report the name of the temporary queue
        std::cout << "declared queue " << name << std::endl;

        // now we can close the connection
        connection.close();
    });

    // run the loop
    ev_run(loop, 0);

    // done
    return 0;*/
}


