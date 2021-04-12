#include "client.h"

client::client(unsigned short int port)
{
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
}

int client::init(string address)
{
    //Creating socket
    if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;  //Socket creation error

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, address.c_str(), &serv_addr.sin_addr)<=0)
        return -2;  //Invalid address/ Address not supported

    return 0;
}

int client::connect()
{
    if (::connect(this->sock, reinterpret_cast<struct sockaddr *>(&serv_addr), sizeof(serv_addr)) < 0)
    {
        //Connection failded
        return -1;
    }

    return 0;
}

byte* client::read()
{
    valread = ::read(this->sock, this->buffer, BUFFER_SIZE);
    
    if (valread)
        return this->buffer;
        
    throw runtime_error("Valread error");
}

void client::send(void *data, ssize_t data_size)
{
    ::send(this->sock, data, data_size, 0);
}
