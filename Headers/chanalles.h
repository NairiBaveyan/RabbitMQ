#include "channel.h"

Channel channel;
/*In the above example we created a channel object. A channel is a sort of virtual
connection, and it is possible to create many channels that all use
the same connection.

AMQP instructions are always sent over a channel, so before you can send the first
command to the RabbitMQ server, you first need a channel object. The channel
object has many methods to send instructions to the RabbitMQ server. It for
example has methods to declare queues and exchanges, to bind and unbind them,
and to publish and consume messages. You can best take a look at the channel.h
C++ header file for a list of all available methods. Every method in it is well
documented.

All operations that you can perform on a channel are non-blocking. This means
that it is not possible for a method (like Channel::declareExchange()) to
immediately return 'true' or 'false'. Instead, almost every method of the Channel
class returns an instance of the 'Deferred' class. This 'Deferred' object can be
used to install handlers that will be called in case of success or failure.

For example, if you call the channel.declareExchange() method, the AMQP-CPP library
will send a message to the RabbitMQ message broker to ask it to declare the
queue. However, because all operations in the library are asynchronous, the
declareExchange() method can not return 'true' or 'false' to inform you whether
the operation was successful or not. Only after a while, after the instruction
has reached the RabbitMQ server, and the confirmation from the server has been
sent back to the client, the library can report the result of the declareExchange()
call.

To prevent any blocking calls, the channel.declareExchange() method returns a
'Deferred' result object, on which you can set callback functions that will be
called when the operation succeeds or fails.
*/

channel.declareExchange();

/*For example, if you call the channel.declareExchange() method, the AMQP-CPP library
will send a message to the RabbitMQ message broker to ask it to declare the
queue. However, because all operations in the library are asynchronous, the
declareExchange() method can not return 'true' or 'false' to inform you whether
the operation was successful or not. Only after a while, after the instruction
has reached the RabbitMQ server, and the confirmation from the server has been
sent back to the client, the library can report the result of the declareExchange()
call.
*/

// create a channel (or use TcpChannel if you're using the Tcp module)
Channel myChannel(&connection);

// declare an exchange, and install callbacks for success and failure
myChannel.declareExchange("my-exchange")

    .onSuccess([]() {
        std::cout<<"Exchange was succesfully created"<<std::endl;
    })

    .onError([](const char *message) {
         std::cout<<"something went wrong creating the exchange"<<std::endl;
    });

    // create a channel (or use TcpChannel if you use the Tcp module)
Channel myChannel(&connection);

// install a generic channel-error handler that will be called for every
// error that occurs on the channel
myChannel.onError([](const char *message) {

    // report error
    std::cout << "channel error: " << message << std::endl;
});

// install a generic callback that will be called when the channel is ready
// for sending the first instruction
myChannel.onReady([]() {

    // send the first instructions (like publishing messages)
});


/*
In theory, you should wait for the onReady() callback to be called before you
send any other instructions over the channel. In practice however, the AMQP library
caches all instructions that were sent too early, so that you can use the
channel object right after it was constructed.
*/