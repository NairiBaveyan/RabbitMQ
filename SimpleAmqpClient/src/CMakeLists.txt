SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_VERBOSE_MAKEFILE ON) #ON

LINK_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/lib)
INCLUDE_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/include)

LINK_DIRECTORIES(/usr/local/Cellar/rabbitmq-c/0.11.0/lib)
INCLUDE_DIRECTORIES(/usr/local/Cellar/rabbitmq-c/0.11.0/include)


ADD_LIBRARY( SAMQPC 

SimpleAmqpClient.h

AmqpException.h
AmqpException.cpp

Bytes.h

Channel.h
Channel.cpp

ChannelImpl.h
ChannelImpl.cpp

BasicMessage.h
BasicMessage.cpp

Util.h

AmqpLibraryException.h
AmqpLibraryException.cpp

AmqpResponseLibraryException.h
AmqpResponseLibraryException.cpp

BadUriException.h
ConnectionClosedException.h
ConsumerTagNotFoundException.h
MessageRejectedException.h

Envelope.h
Envelope.cpp

MessageReturnedException.h
MessageReturnedException.cpp

Table.h
Table.cpp

TableImpl.h
TableImpl.cpp)
TARGET_LINK_LIBRARIES( SAMQPC LINK_PUBLIC ${boost_cstdint} )
TARGET_LINK_LIBRARIES( SAMQPC LINK_PUBLIC ${amqp})

TARGET_LINK_LIBRARIES(SAMQPC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")


