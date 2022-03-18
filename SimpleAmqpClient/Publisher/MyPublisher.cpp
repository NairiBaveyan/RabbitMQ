#include "MyPublisher.hpp"

namespace AmqpClient{

Publisher::Publisher(Channel::ptr_t channel,const std::string &exchange_name)
    :m_channel{ channel },m_exchange{exchange_name}
{
    if(m_exchange == "")
        m_exchange = "Nairi'sExchange";
    m_channel->DeclareExchange(m_exchange);
}


Publisher::~Publisher()
{
    m_channel->DeleteExchange(m_exchange,false);
}

Publisher::ptr_t Publisher::Create(Channel::ptr_t channel,const std::string &publisher_name)
{
    return nullptr;//boost::make_shared<Publisher>(channel,boost::make_shared<std::string*>(&publisher_name));
}

void Publisher::publish(BasicMessage::ptr_t message)
{
    m_channel->BasicPublish(m_exchange,"",message);
}

void Publisher::publish(const std::string &message)
{
    BasicMessage::ptr_t msg = BasicMessage::Create();
    msg->Body(message);
    publish(msg);
}


std::string Publisher::getExchangeName()const
{
    return m_exchange;
}




}

