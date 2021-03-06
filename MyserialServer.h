//
// Created by stavih19 on 12/01/2020.
//

#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H

#include "ServersInterfaces/server_side.h"
#include "ServersInterfaces/ClientHandler.h"

using namespace server_side;

//template<class P, class S>
class MyserialServer : public Server {
private:
    int mainFlag{};

    int returnSocket(int port);

    void runServer(int port, ClientHandler *c);

public:
    void start(int port, ClientHandler *c) override;

    void stop() override;
};


#endif //MILESTONE2_MYSERIALSERVER_H