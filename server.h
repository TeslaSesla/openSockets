#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <stdexcept>

//Read buffer size
#define BUFFER_SIZE 512

using namespace std;

class server
{
public:
    server(unsigned short int);

    int     startListen();
    int     accept();
    byte*   read();
    void    send(void*, ssize_t);

private:
    int     server_fd, new_socket;
    struct  sockaddr_in address;
    ssize_t valread;
    int     opt = 1;

    byte buffer[BUFFER_SIZE];
};

#endif // SERVER_H
