#include <iostream>
#include "/usr/local/Cellar/amqp-cpp/4.3.16/include/amqpcpp.h"
//#include "/usr/local/Cellar/amqp-cpp/4.3.16/include/amqpcpp/libev.h"
//#include "/usr/local/Cellar/amqp-cpp/4.3.16/include/amqpcpp/linux_tcp.h"
#include "MyConnectionHandler.h"
//#include "openssl/ssl.h"
/*
auto callback = [](const std::string &name, int msgcount, int consumercount) {

    std::cout<<name<<std::endl;
    for(int i{};i < msgcount,++i)

};
*/
int main()
{  

// create an instance of your own connection handler
MyConnectionHandler myHandler;
std::cout<<1;
// create a AMQP connection object
try{
AMQP::Connection connection(&myHandler, AMQP::Login("guest","guest"), "/");
myHandler.onReady(&connection);
std::cout<<2;
AMQP::Channel channel(&connection);
std::cout<<3;


/*channel.onReady([](){
    std::cout<<"Publishing message"<<std::endl;
});*/

// use the channel object to call the AMQP method you like


channel.declareExchange("my-exchange", AMQP::fanout)
    .onSuccess([]() {
        std::cout<<"You succesfully declare exchange"<<std::endl;
    })

    .onError([](const char *message) {
        std::cout<<"something went wrong creating the exchange"<<std::endl;
        std::cout<<"  Error :"<<message<<std::endl;
    });
std::cout<<4;
    
channel.declareQueue("my-queue")
    .onSuccess([]() {
        std::cout<<"You succesfully declare Queue"<<std::endl;
    })

    .onError([](const char *message) {
        std::cout<<"something went wrong creating the exchange"<<std::endl;
        std::cout<<"  Error :"<<message<<std::endl;
    });

std::cout<<5;

channel.bindQueue("my-exchange", "my-queue", "my-routing-key");
//AMQP::SuccessCallback callb;
AMQP::Deferred def;
//myHandler.onReady(&connection);
//std::cout<<"ready -"<<connection.ready();
/*
    AMQP::Table arguments;
    arguments["x-dead-letter-exchange"] = "some-exchange";
    arguments["x-message-ttl"] = 3600 * 1000;
    arguments["x-expires"] = 7200 * 1000;
*/
std::cout<<6;


/*channel1.bindQueue(exch, que,myrkey )
.onError([](const char *message){
    std::cout<<"Binding error"<<message<<std::endl;
});*/

//channel.startTransaction();

// publish a number of messages
channel.publish("my-exchange", "my-key", "my first message");
std::cout<<7;
//channel2.publish("my-exchange", "my-key", "another message");
connection.close();
// commit the transactions, and set up callbacks that are called when
// the transaction was successful or not
/*channel.commitTransaction()
    .onSuccess([]() {
        std::cout<<"all messages were successfully published"<<std::endl;
    })
    .onError([](const char *message) {
        std::cout<<" none of the messages were published ->"<<message<<std::endl;
        // now we have to do it all over again
    });
*/

} catch (...)
{
    std::cout<< "injcorban\n";
}
std::cout<<8;
//channel1.close();
//channel2.close();

}
