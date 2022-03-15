#ifndef MYCONHAND_H_
#define MYCONHAND_H_


#include <string>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <amqpcpp.h>
#include <amqpcpp/connectionhandler.h>
#include <amqpcpp/connection.h>
#include "/usr/local/include/boost/chrono.hpp"
#include <SimpleAmqpClient/SimpleAmqpClient.h>


#define MAX 60
#define PORT 5672 //15672
#define SA struct sockaddr
using std::cout;
using std::endl;

void func(int sockfd,char*,size_t );


class MyConnectionHandler : public AMQP::ConnectionHandler
{
public:
    /**
     *  Method that is called by the AMQP library every time it has data
     *  available that should be sent to RabbitMQ.
     *  @param  connection  pointer to the main connection object
     *  @param  data        memory buffer with the data that should be sent to RabbitMQ
     *  @param  size        size of the buffer
     */
    virtual void onData(AMQP::Connection *connection, const char *data, size_t size)
    {
        AMQP::Channel chanell(connection);
        
        // @todo
        //  Add your own implementation, for example by doing a call to the
        //  send() system call. But be aware that the send() call may not
        //  send all data at once, so you also need to take care of buffering
        //  the bytes that could not immediately be sent, and try to send
        //  them again when the socket becomes writable again
   
        
        
        
        int sockfd, connfd;
        struct sockaddr_in servaddr, cli;
        cout<<data<<"Data"<<endl;
   
        // socket create and verification
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("socket creation failed...\n");
            exit(0);
        }
        else
           printf("Socket successfully created..\n");
        bzero(&servaddr, sizeof(servaddr));
   
        // assign IP, PORT
        servaddr.sin_family = AF_INET;//2
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);
            // connect the client socket to server socket
        if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
            cout<<"connection with the server failed...\n";
          exit(0);
        }
        else
            cout<<"connected to the server..\n";
   
        // function for chat
        char buff[size];
        for(int i{};i < size;++i){
            buff[i] = data[i];
        }
        //onReady(connection);
        func(sockfd,buff,size);
   
        // close the socket
        close(sockfd);

        


        std::cout<<"OnData "<<std::endl;
    }
      /**
     *  Method that is called by the AMQP library when the login attempt
     *  succeeded. After this method has been called, the connection is ready
     *  to use.
     *  @param  connection      The connection that can now be used
     */
    virtual void onReady(AMQP::Connection *connection)
    {
        // @todo
        //  add your own implementation, for example by creating a channel
        //  instance, and start publishing or consuming
        AMQP::Channel channel1(connection);
        AMQP::Channel channel2(connection);
        /*while(!connection->ready()){
        
        }*/
        std::cout<<"Connection is ready";

        std::string exch = "Nairis-exchange";
        std::string que = "Nairis-queue";
        std::string myrkey = "Nairis-routing-key";


        channel1.declareQueue(que)
        .onSuccess([]() {
             std::cout<<"You succesfully declare queue"<<std::endl;
        })

        .onError([](const char *message) {
             std::cout<<"something went wrong creating the queue"<<std::endl;
             std::cout<<"  Error :"<<message<<std::endl;
         })
         ;

        channel2.declareExchange(exch)
        .onSuccess([]() {
            std::cout<<"You succesfully declare exchange"<<std::endl;
        })
        .onError([](const char *message) {
             std::cout<<"something went wrong creating the exchange"<<std::endl;
             std::cout<<"  Error :"<<message<<std::endl;
        });

        channel1.bindQueue(exch,que,myrkey);

        
        std::cout<<"onReady"<<connection->ready()<<std::endl;
        std::string msg;

        for(;;)
        {
            std::cout<<"Please input the message"<<std::endl;
            std::getline(std::cin,msg);
            if(msg=="end")
                break;
            channel2.publish(exch,myrkey,myrkey);
            channel1.consume(que)
            .onSuccess([](){
                 std::cout<<"Succesfully consumed"<<std::endl;
             });

        }
    }

    /**
     *  Method that is called by the AMQP library when a fatal error occurs
     *  on the connection, for example because data received from RabbitMQ
     *  could not be recognized.
     *  @param  connection      The connection on which the error occurred
     *  @param  message         A human readable error message
     */
    virtual void onError(AMQP::Connection *connection, const char *message)
    {
        // @todo
        //  add your own implementation, for example by reporting the error
        //  to the user of your program, log the error, and destruct the
        //  connection object because it is no longer in a usable state
        std::cout<<" error: "<<message<<std::endl;
        //connection->fail();
        //connection->close();
    }

    /**
     *  Method that is called when the connection was closed. This is the
     *  counter part of a call to Connection::close() and it confirms that the
     *  AMQP connection was correctly closed.
     *
     *  @param  connection      The connection that was closed and that is now unusable
     */
    virtual void onClosed(AMQP::Connection *connection) 
    {
        // @todo
        //  add your own implementation, for example by closing down the
        //  underlying TCP connection too
        connection->close();
    }


};




void func(int sockfd,char* buff,size_t size)
{


    send(sockfd, buff, strlen(buff),0);
    //char buff[MAX];
   /int n;
    for (;;) {
        bzero(buff, strlen(buff));
        cout<<"Enter the string : "<<endl;
        //n = 0;
        //while ((buff[n++] = getchar()) != '\n'){}
        //onRead
        std::cout<< __LINE__ <<buff<<std::endl;
        send(sockfd, buff, strlen(buff),0);
        std::cout<< __LINE__ <<std::endl;
        bzero(buff, strlen(buff));
        std::cout<< __LINE__ <<std::endl;
        read(sockfd, buff, sizeof(buff));
        std::cout<< __LINE__ <<std::endl;
        cout<<"From Server : "<< buff<<endl;
        if ((strncmp(buff, "exit", 4)) == 0) {
            cout<<"Client Exit..."<<endl;
            break;
        }
    
}

#endif