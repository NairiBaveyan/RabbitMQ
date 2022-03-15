cmake_minimum_required(VERSION 3.12)
project(SimpleAmqpClientLib VERSION 1.0.3)


add_library( SAMQPC SHARED

src/SimpleAmqpClient.h

src/SimpleAmqpClient/AmqpException.h
src/AmqpException.cpp

src/SimpleAmqpClient/Bytes.h

src/SimpleAmqpClient/Channel.h
src/Channel.cpp

src/SimpleAmqpClient/ChannelImpl.h
src/ChannelImpl.cpp

src/SimpleAmqpClient/BasicMessage.h
src/BasicMessage.cpp

src/SimpleAmqpClient/Util.h

src/SimpleAmqpClient/AmqpLibraryException.h
src/AmqpLibraryException.cpp

src/SimpleAmqpClient/AmqpResponseLibraryException.h
src/AmqpResponseLibraryException.cpp

src/SimpleAmqpClient/BadUriException.h
src/SimpleAmqpClient/ConnectionClosedException.h
src/SimpleAmqpClient/ConsumerTagNotFoundException.h
src/SimpleAmqpClient/MessageRejectedException.h

src/SimpleAmqpClient/Envelope.h
src/Envelope.cpp

src/SimpleAmqpClient/MessageReturnedException.h
src/MessageReturnedException.cpp

src/SimpleAmqpClient/Table.h
src/Table.cpp

src/SimpleAmqpClient/TableImpl.h
src/TableImpl.cpp
)

target_link_libraries(SAMQPC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")


