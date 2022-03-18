#include <iostream>
#include <string>   
#include "../src/SimpleAmqpClient.h"
#include "../Publisher/MyPublisher.hpp"
using namespace AmqpClient;

int main()
{
    Channel::OpenOpts opts = Channel::OpenOpts::FromUri("amqp://[guest[:guest]@]");
    Channel::ptr_t connection = Channel::Open(opts);
    Publisher myPub(connection,"NairiEX");
    
    int count_of_msg{100};

    for(int i{};i < count_of_msg;++i){
        
        const std::string body = ("message<" + std::to_string(i) + std::string(">"));
        myPub.publish(body);
    }
    system("./main1");
}
