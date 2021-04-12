#include "server.h"

server::server(unsigned short int port)
{
    this->address.sin_family      = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port        = htons(port);
}

int server::startListen()
{
    // Creating socket file descriptor
    if ((this->server_fd = socket(this->address.sin_family, SOCK_STREAM, 0)) == 0)
    {
        //Socket failed
        return -1;
    }

    // Forcefully attaching socket to the port
    if (setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        //setsockopt
        return -2;
    }

    // Forcefully attaching socket to the port
    if (bind(this->server_fd, reinterpret_cast<struct sockaddr *>(&address), sizeof(address)) < 0)
    {
        //Bind failed
        return -3;
    }

    //Starting listening
    if (listen(this->server_fd, 3) < 0)
    {
        //Listen
        return -4;
    }

    return 0;
}

int server::accept()
{
    int addrlen = sizeof(address);

    if ((this->new_socket = ::accept(server_fd, reinterpret_cast<struct sockaddr *>(&address), reinterpret_cast<socklen_t*>(&addrlen))) < 0)
    {
        return -1;
    }

    return 0;
}

int server::send(string message)
{
    //Call from global namespace in sys/socket.h
    ::send(this->new_socket, message.c_str(), message.length(), 0);
    return 0;
}

byte* server::read()
{
    valread = ::read(this->new_socket, this->buffer, 4096);
    
    if (valread)
        return this->buffer;

    throw runtime_error("Valread error");
}
