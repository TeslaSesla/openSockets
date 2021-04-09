#include <iostream>

#include "server.h"
#include "client.h"

using namespace std;

int main()
{
    int select = 0;
    cout << "Server - 0" << endl <<
            "Client - 1" << endl <<
            "Exit   - 2" << endl <<
            "> ";
    cin >> select;

    //Server side
    if (select == 0)
    {
        server myServer(8080);

        myServer.startListen();
        myServer.accept();

        cout << myServer.read();
        myServer.send("Hello!");
    }
    //Client side
    else if (select == 1)
    {
        client myClient(8080);
        myClient.init("127.0.0.1");
        myClient.connect();

        char *str = "Hello world";

        myClient.send(str, sizeof(str));
        cout << myClient.read() << endl;
    }
    else if (select == 2)
        cout << "Goodbue" << endl;
    else
        cout << "Unknown mode selected" << endl;

    return 0;
}
