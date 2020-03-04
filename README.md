# openSockets
*NIX-based TCP client/server with OOP structure

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

string message = myServer.read(); //Read message  
myServer.sendPacket("Hello!");    //Send message
```

### Client class
