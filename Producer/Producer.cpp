#include <iostream>
#include <string>
#include "Producer.h"

int Producer::m_index = 0;

Producer::Producer()
:m_limit{10},m_message{"Message"}
{}

Producer::Producer(std::string msg,int limit)
: m_message{msg},m_limit{limit}
{
	start();
}

Producer::~Producer()
{

}


void Producer::setMessage(std::string msg)
{
	m_message = msg;
}

void Producer::setLimit(int limit)
{
	m_limit  = limit;
}

std::string Producer::getMessage()const
{
	return m_message;
}

int Producer::getLimit()const
{
	return m_limit;
}

int Producer::getIndex()
{
	return m_index;
}

std::string Producer::produceMessage()
{
	std::string tmp{'<'};
	tmp += std::to_string(Producer::m_index);
	tmp.push_back('>');
	++Producer::m_index;
	return m_message + " " + tmp;
}

void Producer::start()
{
	for(int i{};i < m_limit;++i){
		sendMessage(produceMessage());
	}
}

void Producer::sendMessage(std::string msg)
{
	std::cout<<msg<<std::endl;
	//send details
}



