#ifndef PUBLISHER_H_
#define PUBLISHER_H_


#include <utility>
#include <iostream>
#include <string>
#include "/Users/coderepublic1/Downloads/Nairi/MainProject/myProject/src/SimpleAmqpClient/Channel.h"
#include "/Users/coderepublic1/Downloads/Nairi/MainProject/myProject/src/SimpleAmqpClient/Util.h"
#include "/Users/coderepublic1/Downloads/Nairi/MainProject/myProject/src/SimpleAmqpClient/BasicMessage.h"


namespace AmqpClient{

class Publisher{
public:
    typedef std::shared_ptr<Publisher> ptr_t;



    explicit Publisher(Channel::ptr_t channel,const std::string &publisher_name);
    virtual ~Publisher();

public:
    static ptr_t Create(Channel::ptr_t channel,const std::string &publisher_name = "" );
    std::string getExchangeName()const;
    void publish(const std::string &message);
    void publish(BasicMessage::ptr_t message);


private:
    std::string m_exchange;
    Channel::ptr_t m_channel;
};


}

#endif PUBLISHER_H_