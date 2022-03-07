#include <iostream>
#include <fstream>
#include <boost/asio/associated_allocator.hpp>
//#include "Producer.h"


int main()
{
	/**
 *  Publish a message to an exchange
 *
 *  You have to supply the name of an exchange and a routing key. RabbitMQ will then try
 *  to send the message to one or more queues. With the optional flags parameter you can
 *  specify what should happen if the message could not be routed to a queue. By default,
 *  unroutable message are silently discarded.
 *
 *  If you set the 'mandatory' and/or 'immediate' flag, messages that could not be handled
 *  are returned to the application. Make sure that you have called the recall()-method and
 *  have set up all appropriate handlers to process these returned messages before you start
 *  publishing.
 *
 *  The following flags can be supplied:
 *
 *      -   mandatory   If set, server returns messages that are not sent to a queue
 *      -   immediate   If set, server returns messages that can not immediately be forwarded to a consumer.
 *
 *  @param  exchange    the exchange to publish to
 *  @param  routingkey  the routing key
 *  @param  envelope    the full envelope to send
 *  @param  message     the message to send
 *  @param  size        size of the message
 *  @param  flags       optional flags
 */
bool publish(const std::string &exchange, const std::string &routingKey, const Envelope &envelope, int flags = 0) { return _implementation->$
bool publish(const std::string &exchange, const std::string &routingKey, const std::string &message, int flags = 0) { return _implementation$
bool publish(const std::string &exchange, const std::string &routingKey, const char *message, size_t size, int flags = 0) { return _implemen$
bool publish(const std::string &exchange, const std::string &routingKey, const char *message, int flags = 0) { return _implementation->publi$


// start a transaction
channel.startTransaction();

// publish a number of messages
channel.publish("my-exchange", "my-key", "my first message");
channel.publish("my-exchange", "my-key", "another message");

// commit the transactions, and set up callbacks that are called when
// the transaction was successful or not
channel.commitTransaction()
    .onSuccess([]() {
        // all messages were successfully published
    })
    .onError([](const char *message) {
        // none of the messages were published
        // now we have to do it all over again
    });
	
}


// setup confirm mode and ack/nack callbacks (from this moment onwards
// ack/nack confirmations are coming in)
channel.confirmSelect().onSuccess([&]() {

    // publish the first message (this will be acked/nacked with deliveryTag=1)
    channel.publish("my-exchange", "my-key", "my first message");

    // publish the second message (this will be acked/nacked with deliveryTag=2)
    channel.publish("my-exchange", "my-key", "my second message");

}).onAck([&](uint64_t deliveryTag, bool multiple) {

    // deliveryTag is message number
    // multiple is set to true, if all messages UP TO deliveryTag have been processed

}).onNack([&](uint64_t deliveryTag, bool multiple, bool requeue) {

    // deliveryTag is message number
    // multiple is set to true, if all messages UP TO deliveryTag have not been processed
    // requeue is to be ignored

});
