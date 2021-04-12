# openSockets
*NIX-based TCP client/server with OOP structure

[![CMake](https://github.com/TeslaSesla/openSockets/actions/workflows/cmake.yml/badge.svg?branch=master)](https://github.com/TeslaSesla/openSockets/actions/workflows/cmake.yml)


### Include
```C++
#include "server.h" //Server class
#include "client.h" //Client class
```

### Server class
```C++
unsigned short int port = 50253;  //Client/server port
server myServer(port);
myServer.startListen(); //Open server for listening
myServer.accept();      //Accept connection

string message = reinterpret_cast<char*>(myServer.read()); //Read message

char str[] = "Hello!";  //Message
myServer.send(str, sizeof(str));    //Send message
```

### Client class
```C++
unsigned short int port = 50253;  //Client/server port
client myClient(port);
myClient.init("127.0.0.1"); //Initializate connection
myClient.connect();         //Create connection

char str[] = "Hello!";  //Message
myClient.send(str, sizeof(str));  //Send message
cout << reinterpret_cast<char*>(myClient.read()) << endl;  //Read message
```
