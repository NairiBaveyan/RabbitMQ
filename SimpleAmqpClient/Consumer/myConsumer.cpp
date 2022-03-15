#include "myConsumer.hpp"

namespace AmqpClient{


Consumer::Consumer(Channel::ptr_t channel,const std::string &publisher_name)
: m_channel{ channel }
{
    m_queue_name = "Nairi'sQueue";

    m_channel->DeclareQueue(m_queue_name);
    m_channel->BindQueue(m_queue_name,publisher_name,"");
    m_channel->BasicConsume(m_consumerQueue, m_consumerQueue);
}

Consumer::~Consumer() = default;
    //m_channel->Close();


ptr_t Consumer::Create(Channel::ptr_t channel,const std::string &publisher_name)
{
    return std::make_shared<Consumer>(channel,publisher_name);
}

std::string Consumer::waitForStrMsg(int time_out)
{
    BasicMessage::ptr_t msg = waitForMsg(time_out);
    return msg->Body();
}

BasicMessage::ptr_t Consumer::waitForMsg(int time_out)
{
    Envelope::ptr_t envelope;
    m_channel->BasicConsumeMessage(m_queue_name,envelope,time_out);
    return envelope->Message();
}

} //end of AmqpClient namespace