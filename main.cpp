#include <iostream>

#include "server.h"
#include "client.h"

using namespace std;

int main()
{
    int select = 0;
    cout << "Server - 0" << endl <<
            "Client - 1" << endl <<
            "> ";
    cin >> select;

    //Server side
    if (select == 0)
    {
        server myServer(8080);

        myServer.startListen();
        myServer.accept();

        cout << myServer.read();
        myServer.sendPacket("Hello!");
    }
    //Client side
    else if (select == 1)
    {
        client myClient(8080);
        myClient.init("127.0.0.1");
        myClient.connect();
        myClient.send("Hi!");
        cout << myClient.read() << endl;
    }
    else
        cout << "Unknown mode selected" << endl;

    return 0;
}
