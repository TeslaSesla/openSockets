#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>

using namespace std;

class server
{
public:
    server(unsigned short int);

    int     startListen();
    int     accept();
    string  read();
    int     send(string);

private:
    int     server_fd, new_socket;
    struct  sockaddr_in address;
    ssize_t valread;
    int     opt = 1;
};

#endif // SERVER_H
