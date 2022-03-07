#ifndef PRODUCER_H_
#define PRODUCER_H_



class Producer{
public:
	Producer();
	Producer(std::string,int);
	~Producer();

	Producer(const Producer&) = delete;
	Producer& operator = (const Producer&) = delete;
	Producer(Producer&&) = delete;
	Producer& operator = (Producer&&) = delete;

public:
	void start();
	void setMessage(std::string);
	void setLimit(int);

	std::string getMessage()const;
	static int getIndex();
	int getLimit()const;

private:
	std::string produceMessage();
	void sendMessage(std::string);

private:
	static int m_index;
	int m_limit{};
	std::string m_message;
};


#endif  //PRODUCER_H_
