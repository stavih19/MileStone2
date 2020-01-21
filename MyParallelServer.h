//
// Created by stavih19 on 20/01/2020.
//

#ifndef MILESTONE2_MYPARALLELSERVER_H
#define MILESTONE2_MYPARALLELSERVER_H

#include "ServersInterfaces/server_side.h"

using namespace server_side;

class MyParallelServer : public server_side::Server {
private:
    bool mainFlag;
    vector<thread *> threads;
    int socketServerSaved;
    sockaddr_in* addressServerSaved;
    ClientHandler *clientHandlerSaved;

    void startConverstion();

public:
    void start(int port, ClientHandler *c) override;

    void stop() override;
};


#endif //MILESTONE2_MYPARALLELSERVER_H
