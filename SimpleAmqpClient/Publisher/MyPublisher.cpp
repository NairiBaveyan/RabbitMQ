#include "MyPublisher.hpp"

namespace AmqpClient{

Publisher::Publisher(Channel::ptr_t channel,const std::string &exchange_name)
    :m_channel{ chanell },m_exchange{exchange_name}
{
    if(m_exchange == "")
        m_exchange = "Nairi'sExchange";
    m_channel->DeclareExchange(m_exchange);
}


Publisher::~Publisher()
{
    m_channel->DeleteExchange(m_exchange,false);
}

ptr_t Publisher::Create(Channel::ptr_t channel,const std::string &message = "")
{
    return std::make_shared<Publisher>(channel,&message);
}

void Publisher::publish(BasicMessage::ptr_t message)
{
    m_channel->BasicPublish(m_exchange,"",message);
}

void Publisher::publish(const std::message &message)
{
    BasicMessage::ptr_t msg = BasicMessage::Create();
    msg->Body(message);
    publish(msg)
}


std::string Publisher::getExchangeName()const
{
    return m_exchange;
}




}

