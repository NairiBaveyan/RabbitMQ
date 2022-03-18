#ifndef PUBLISHER_H_
#define PUBLISHER_H_
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <utility>
#include <iostream>
#include <string>
#include "../src/Channel.h"
#include "../src/Util.h"
#include "../src/BasicMessage.h"


namespace AmqpClient{

class Publisher{
public:
    typedef boost::shared_ptr<Publisher> ptr_t;

    virtual ~Publisher();

public:
    static ptr_t Create(Channel::ptr_t channel,const std::string &publisher_name ="");
    Publisher(Channel::ptr_t channel,const std::string &publisher_name);
    std::string getExchangeName()const;
    void publish(const std::string &message);
    void publish(BasicMessage::ptr_t message);


private:
    std::string m_exchange;
    Channel::ptr_t m_channel;
};


}

#endif //PUBLISHER_H_