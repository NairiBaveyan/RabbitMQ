#ifndef CONSUMER_H_
#define CONSUMER_H_
#include <string>
#include <utility>


#include "../src/BasicMessage.h"
#include "../src/Channel.h"
#include "../src/Util.h"


namespace AmqpClient{

class Consumer{
public:
    typedef std::shared_ptr<Consumer> ptr_t;

    Consumer(Channel::ptr_t channel,const std::string &publisher_name);
    virtual ~Consumer();
    Consumer(const Consumer&) = delete;
    Consumer& operator=(const Consumer&) = delete;

public:
    static ptr_t Create(Channel::ptr_t channel,const std::string &publisher_name); 
    std::string waitForStrMsg(int time_out = -1);
    BasicMessage::ptr_t waitForMsg(int time_out = -1);
    

private:
    std::string m_queue_name;
    Channel::ptr_t m_channel;

};  //end of Consumer


}   //end of namespace

#endif