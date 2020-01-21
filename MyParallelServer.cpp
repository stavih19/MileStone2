//
// Created by stavih19 on 20/01/2020.
//

#include "MyParallelServer.h"

void MyParallelServer::start(int port, ClientHandler *c) {
    mainFlag = true;

    int enable = 1;
    int firstEnterance = 0;

    // open the server socket
    sockaddr_in addressServer{};

    int socketServer = socket(AF_INET, SOCK_STREAM, 0);

    if (socketServer == -1) {
        cout << "Could not create a socket" << endl;
    }

    //define the adress
    addressServer.sin_family = AF_INET;
    addressServer.sin_addr.s_addr = INADDR_ANY;
    addressServer.sin_port = htons(port);

    int isBind = bind(socketServer, (struct sockaddr *) &addressServer, sizeof(addressServer));
    if (isBind == -1) {
        firstEnterance = 1;
    }

    //in case we had bind before
    if (firstEnterance && setsockopt(socketServer, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        cout << "Could not bind again socket to an IP" << endl;
    }

    int isListen = listen(socketServer, 5);
    if (isListen == -1) {
        cout << "Error during listening command" << endl;
    }

    //define timeout
    struct timeval tv{};
    tv.tv_sec = 120; // 2 mints
    tv.tv_usec = 0;
    setsockopt(socketServer, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));

    //save the relevant properties
    socketServerSaved = socketServer;
    addressServerSaved = &addressServer;
    clientHandlerSaved = c;

    //working in parallel operations
    while (mainFlag) {
        //MyParallelServer MS;
        startConverstion();
        //threads.push_back(new thread(&MyParallelServer::startConverstion, &MS));
    }
}

void MyParallelServer::stop() {
    mainFlag = false;

    //for (auto thread:threads) { thread->join(); }
}

void MyParallelServer::startConverstion() {
    int data;
    char buffer[1024];
    string output;
    bool endConverstion = false;
    vector<string> problems, solutions;

    int isAccept = accept(socketServerSaved, (struct sockaddr *) &addressServerSaved,
                          (socklen_t *) &addressServerSaved);
    if (isAccept == -1) {
        endConverstion = true;
    }
    socketServerSaved = isAccept;

    while (!endConverstion && mainFlag) {
        bzero(buffer, 1024);
        data = read(socketServerSaved, buffer, 1024);

        for (int i = 0; i < data; ++i)
            if (buffer[i] != '\r') { output += buffer[i]; }

        output = output.substr(0, output.length() - 1);

        if (output == "end") { endConverstion = true; }
        else { problems.push_back(output); }
        output = "";
    }

    if (!endConverstion && mainFlag) {
        solutions = clientHandlerSaved->handleClient(problems);

        for (auto solution:solutions) { write(socketServerSaved, solution.c_str(), solution.size()); }
    }

    close(socketServerSaved);
}
