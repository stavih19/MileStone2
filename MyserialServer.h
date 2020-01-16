//
// Created by stavih19 on 12/01/2020.
//

#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H

#include "server_side.h"
#include "ClientHandler.h"

using namespace server_side;

class MyserialServer : public server_side::Server {
private:
    int mainFlag;

    int returnSocket(int port);

    void runServer(int port, ClientHandler *c);

public:
    void start(int port, ClientHandler *c) override;

    void stop() override;
};


#endif //MILESTONE2_MYSERIALSERVER_H