//
// Created by stavih19 on 20/01/2020.
//

#include "MyParallelServer.h"

void MyParallelServer::start(int port, ClientHandler *c) {
    int socketServer = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addressServer{};

    if (socketServer == -1) {
        cout << "Could not create a socket" << endl;
        return;
    }

    //define the adress
    addressServer.sin_family = AF_INET;
    addressServer.sin_addr.s_addr = INADDR_ANY;
    addressServer.sin_port = htons(port);

    int isBind = bind(socketServer, (struct sockaddr *) &addressServer,
                      sizeof(addressServer));
    if (isBind == -1) {
        cout << "Could not bind the socket to an IP" << endl;
    }

    int isListen = listen(socketServer, SOMAXCONN);
    if (isListen == -1) {
        cout << "Error during listening command" << endl;
        return;
    }
    openPort(socketServer, addressServer, c);
}

void MyParallelServer::openPort(int clientSocket, sockaddr_in address, ClientHandler *clientHandler) {
    int enable = 1;
    int firstEnterance = 0;
    int mainFlag = 1;

    while (mainFlag) {
        if (firstEnterance) {
            //define timeout
            struct timeval tv{};
            tv.tv_sec = 120; // 2 mints
            tv.tv_usec = 0;
            setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));

            //in case we had bind before
            if (setsockopt(clientSocket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
                cout << "Could not bind again socket to an IP" << endl;
                return;
            }
        }

        int isAccept = accept(clientSocket, (struct sockaddr *) &address, (socklen_t *) &address);
        if (isAccept == -1) {
            cout << "Error during accepting command" << endl;
            return;
        }

        firstEnterance = 1;
        //working in parallel operations
        MyParallelServer MS;
        threads.push_back(new thread(startConverstion, isAccept, clientHandler));
    }
}

void MyParallelServer::stop() {
    for (auto thread:threads) { thread->join(); }
}

void MyParallelServer::startConverstion(int clientSocket, ClientHandler *clientHandler) {
    int data;
    char buffer[1024];
    string output;
    bool endConverstion = false;
    vector<string> problems, solutions;

    while (!endConverstion) {
        bzero(buffer, 1024);
        data = read(clientSocket, buffer, 1024);

        for (int i = 0; i < data; ++i)
            if (buffer[i] != '\r') {
                output += buffer[i];
            }
        output = output.substr(0, output.length() - 1);

        if (output == "end") {
            endConverstion = true;
        } else if (!output.empty()) {
            problems.push_back(output);
        }
        output = "";
    }

    solutions = clientHandler->handleClient(problems);
    for (auto solution:solutions) { write(clientSocket, solution.c_str(), solution.size()); }

    close(clientSocket);
}