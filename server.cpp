#include "server.h"

server::server(unsigned short int port)
{
    address.sin_family      = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port        = htons(port);
}

int server::startListen()
{
    //exit(EXIT_FAILURE);
    //perror("listen");

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        //Socket failed
        return -1;
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        //setsockopt
        return -2;
    }

    // Forcefully attaching socket to the port
    if (bind(server_fd, reinterpret_cast<struct sockaddr *>(&address), sizeof(address)) < 0)
    {
        //Bind failed
        return -3;
    }

    //Starting listening
    if (listen(server_fd, 3) < 0)
    {
        //Listen
        return -4;
    }

    return 0;
}

int server::accept()
{
    int addrlen = sizeof(address);

    if ((new_socket = ::accept(server_fd, reinterpret_cast<struct sockaddr *>(&address), reinterpret_cast<socklen_t*>(&addrlen))) < 0)
    {
        return -1;
    }

    return 0;
}

int server::send(string message)
{
    //Call from global namespace in sys/socket.h
    ::send(new_socket, message.c_str(), message.length(), 0);
    return 0;
}

string server::read()
{
    char buffer[4096];
    string message = "";
    valread = ::read(new_socket, buffer, 4096);
    if (valread)
        message = string(buffer, static_cast<unsigned long>(valread));

    return message;
}
