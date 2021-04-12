#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

#define BUFFER_SIZE 512

class client
{
public:
    client(unsigned short int);

    int     init(string address);
    int     connect();
    byte*   read();
    void    send(void*, size_t);

private:
    int sock = 0;
    ssize_t valread;
    struct sockaddr_in serv_addr;

    byte buffer[BUFFER_SIZE];

};

#endif // CLIENT_H
