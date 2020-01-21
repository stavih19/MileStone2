//
// Created by stavih19 on 20/01/2020.
//

#ifndef MILESTONE2_MYPARALLELSERVER_H
#define MILESTONE2_MYPARALLELSERVER_H

#include "ServersInterfaces/server_side.h"
#include <sys/time.h>

using namespace server_side;

class MyParallelServer : public Server {
private:
    vector<thread *> threads;

    static void startConverstion(int clientSocket, ClientHandler *clientHandler);

    void openPort(int clientSocket, sockaddr_in address, ClientHandler *clientHandler);

public:
    void start(int port, ClientHandler *c) override;

    void stop() override;
};


#endif //MILESTONE2_MYPARALLELSERVER_H
