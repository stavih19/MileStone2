//
// Created by stavih19 on 12/01/2020.
//

#include "MyserialServer.h"
#include <sys/time.h>

//template<class P, class S>
void MyserialServer::start(int port, ClientHandler *c) {
    mainFlag = 1;

    MyserialServer MS;
    thread getSocket(&MyserialServer::runServer, &MS, port, c);
    getSocket.detach();
}

//template<class P, class S>
void MyserialServer::stop() {
    MyserialServer::mainFlag = 0;
}

//template<class P, class S>
void MyserialServer::runServer(int port, ClientHandler *c) {
    int data;
    char buffer[1024] = {0};
    string output;
    int socketClient = 0;
    int endConnection = 0;
    int runFlag = 1;
    vector<string> solutions, problems;


    while (mainFlag && runFlag) {
        socketClient = returnSocket(port);
        if (socketClient == -4) {
            runFlag = 0;
            endConnection = 1;
        }

        while (!endConnection && mainFlag) {
            bzero(buffer, 1024);
            data = read(socketClient, buffer, 1024);

            for (int i = 0; i < data; i++) {
                if (buffer[i] != '\r') {
                    output += buffer[i];
                }
            }
            output = output.substr(0, output.length() - 1);

            if (output == "end") {
                endConnection = 1;
            } else {
                problems.push_back(output);
            }
            output = "";
        }
        solutions = c->handleClient(problems);

        for (auto &solution : solutions) {
            write(socketClient, solution.c_str(), solution.size());
        }

        close(socketClient);

    } // end while loop
}

//template<class P, class S>
int MyserialServer::returnSocket(int port) {
    int enable = 1;
    int firstEnterance = 0;

    // open the server socket
    sockaddr_in addressServer{};

    int socketServer = socket(AF_INET, SOCK_STREAM, 0);

    if (socketServer == -1) {
        cout << "Could not create a socket" << endl;
        return -1;
    }

    addressServer.sin_family = AF_INET;
    addressServer.sin_addr.s_addr = INADDR_ANY;
    addressServer.sin_port = htons(port);

    int isBind = bind(socketServer, (struct sockaddr *) &addressServer, sizeof(addressServer));
    if (isBind == -1) {
        //cout << "Could not bind the socket to an IP" << endl;
        //return -3;
        firstEnterance = 1;
    }

    if (firstEnterance && setsockopt(socketServer, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        cout << "Could not bind again socket to an IP" << endl;
        return -2;
    }

    int isListen = listen(socketServer, 5);
    if (isListen == -1) {
        cout << "Error during listening command" << endl;
        return -4;
    }

    struct timeval tv{};
    tv.tv_sec = 120;
    tv.tv_usec = 0;
    setsockopt(socketServer, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));
    int isClientSocket = accept(socketServer, (struct sockaddr *) &addressServer, (socklen_t *) &addressServer);
    if (isClientSocket == -1) {
        cout << "Error accepting client" << endl;
        return -5;
    }

    return isClientSocket;
}