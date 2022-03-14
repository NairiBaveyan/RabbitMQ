/*TCP CONNECTIONS
===============

Although the AMQP-CPP library gives you extreme flexibility by letting you setup
your own network connections, the reality is that most if not all AMQP connections
use the TCP protocol. To help you out, the library therefore also comes with a
TCP module that takes care of setting up the network connections, and sending
and receiving the data.

If you want to use this TCP module, you should not use the AMQP::Connection
and AMQP::Channel classes that you saw above, but the alternative AMQP::TcpConnection
and AMQP::TcpChannel classes instead. You also do not have to create your own class
that implements the "AMQP::ConnectionHandler" interface - but a class that inherits
from "AMQP::TcpHandler" instead. This AMQP::TcpHandler class contains a set of
methods that you can override to intercept all sort of events that occur during the
TCP and AMQP connection lifetime. Overriding these methods is mostly optional, because
almost all have a default implementation. But you do need to implement the 
"monitor()" method, as that is needed by the AMQP-CPP library to interact with
the main event loop:
 */


#include <amqpcpp/linux_tcp.h>
#include <amqpcpp.h>

class MyTcpHandler : public AMQP::TcpHandler
{
    /**
     *  Method that is called by the AMQP library when a new connection
     *  is associated with the handler. This is the first call to your handler
     *  @param  connection      The connection that is attached to the handler
     */
    virtual void onAttached(AMQP::TcpConnection *connection) override
    {
        // @todo
        //  add your own implementation, for example initialize things
        //  to handle the connection.
    }
    /**
     *  Method that is called by the AMQP library when the TCP connection 
     *  has been established. After this method has been called, the library
     *  still has take care of setting up the optional TLS layer and of
     *  setting up the AMQP connection on top of the TCP layer., This method 
     *  is always paired with a later call to onLost().
     *  @param  connection      The connection that can now be used
     */
    virtual void onConnected(AMQP::TcpConnection *connection) override
    {
        // @todo
        //  add your own implementation (probably not needed)
    }
    /**
     *  Method that is called when the secure TLS connection has been established. 
     *  This is only called for amqps:// connections. It allows you to inspect
     *  whether the connection is secure enough for your liking (you can
     *  for example check the server certificate). The AMQP protocol still has
     *  to be started.
     *  @param  connection      The connection that has been secured
     *  @param  ssl             SSL structure from openssl library
     *  @return bool            True if connection can be used
     */
    virtual bool onSecured(AMQP::TcpConnection *connection, const SSL *ssl) override
    {
        // @todo
        //  add your own implementation, for example by reading out the
        //  certificate and check if it is indeed yours
        return true;
    }
    /**
     *  Method that is called by the AMQP library when the login attempt
     *  succeeded. After this the connection is ready to use.
     *  @param  connection      The connection that can now be used
     */
    virtual void onReady(AMQP::TcpConnection *connection) override
    {
        // @todo
        //  add your own implementation, for example by creating a channel
        //  instance, and start publishing or consuming
    }

    /**
     *  Method that is called by the AMQP library when a fatal error occurs
     *  on the connection, for example because data received from RabbitMQ
     *  could not be recognized, or the underlying connection is lost. This
     *  call is normally followed by a call to onLost() (if the error occurred
     *  after the TCP connection was established) and onDetached().
     *  @param  connection      The connection on which the error occurred
     *  @param  message         A human readable error message
     */
    virtual void onError(AMQP::TcpConnection *connection, const char *message) override
    {
        // @todo
        //  add your own implementation, for example by reporting the error
        //  to the user of your program and logging the error
    }

    /**
     *  Method that is called when the AMQP protocol is ended. This is the
     *  counter-part of a call to connection.close() to graceful shutdown
     *  the connection. Note that the TCP connection is at this time still 
     *  active, and you will also receive calls to onLost() and onDetached()
     *  @param  connection      The connection over which the AMQP protocol ended
     */
    virtual void onClosed(AMQP::TcpConnection *connection) override 
    {
        // @todo
        //  add your own implementation (probably not necessary, but it could
        //  be useful if you want to do some something immediately after the
        //  amqp connection is over, but do not want to wait for the tcp 
        //  connection to shut down
    }

    /**
     *  Method that is called when the TCP connection was closed or lost.
     *  This method is always called if there was also a call to onConnected()
     *  @param  connection      The connection that was closed and that is now unusable
     */
    virtual void onLost(AMQP::TcpConnection *connection) override 
    {
        // @todo
        //  add your own implementation (probably not necessary)
    }
    /**
     *  Final method that is called. This signals that no further calls to your
     *  handler will be made about the connection.
     *  @param  connection      The connection that can be destructed
     */
    virtual void onDetached(AMQP::TcpConnection *connection) override 
    {
        // @todo
        //  add your own implementation, like cleanup resources or exit the application
    } 

    /**
     *  Method that is called by the AMQP-CPP library when it wants to interact
     *  with the main event loop. The AMQP-CPP library is completely non-blocking,
     *  and only make "write()" or "read()" system calls when it knows in advance
     *  that these calls will not block. To register a filedescriptor in the
     *  event loop, it calls this "monitor()" method with a filedescriptor and
     *  flags telling whether the filedescriptor should be checked for readability
     *  or writability.
     *
     *  @param  connection      The connection that wants to interact with the event loop
     *  @param  fd              The filedescriptor that should be checked
     *  @param  flags           Bitwise or of AMQP::readable and/or AMQP::writable
     */
    virtual void monitor(AMQP::TcpConnection *connection, int fd, int flags) override
    {
        // @todo
        //  add your own implementation, for example by adding the file
        //  descriptor to the main application event loop (like the select() or
        //  poll() loop). When the event loop reports that the descriptor becomes
        //  readable and/or writable, it is up to you to inform the AMQP-CPP
        //  library that the filedescriptor is active by calling the
        //  connection->process(fd, flags) method.
    }


    /**
     *  Method that is called when the server tries to negotiate a heartbeat
     *  interval, and that is overridden to get rid of the default implementation
     *  (which vetoes the suggested heartbeat interval), and accept the interval
     *  instead.
     *  @param  connection      The connection on which the error occurred
     *  @param  interval        The suggested interval in seconds
     */
    virtual uint16_t onNegotiate(AMQP::TcpConnection *connection, uint16_t interval)
    {
        // we accept the suggestion from the server, but if the interval is smaller
        // that one minute, we will use a one minute interval instead
        if (interval < 60) interval = 60;

        // @todo
        //  set a timer in your event loop, and make sure that you call
        //  connection->heartbeat() every _interval_ seconds if no other
        //  instruction was sent in that period.

        // return the interval that we want to use
        return interval;
    }
    /**
     *  Method that is called right after the TLS connection has been created.
     *  In this method you can check the connection properties (like the certificate)
     *  and return false if you find it not secure enough
     *  @param  connection      the connection that has just completed the tls handshake
     *  @param  ssl             SSL structure from the openssl library
     *  @return bool            true if connection is secure enough to start the AMQP protocol
     */
    
    /**
     *  All other methods (like onConnected(), onError(), etc) are left out of this
     *  example, but would be here if this was an actual user space handler class.
     */

};
