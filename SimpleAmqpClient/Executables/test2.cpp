#include <iostream>
#include <cstdlib>  
#include <string>   
#include "src/SimpleAmqpClient.h"
#include <Publisher/myPublisher.hpp>


int main()
{
    Channel::OpenOpts opts = Channel::OpenOpts::FromUri("amqp://[guest[:guest]@]");
    Channel::ptr_t connection = Channel::Open(opts);
    
    for(int i{};i < count_of_msg;++i){
        
          const std::string body = ("message" + '<' + std::to_string(i) + '>');
          BasicMessage::ptr_t out_message = BasicMessage::Create(body);
          connection->BasicPublish("N-exchange", "",out_message);
    }
}
