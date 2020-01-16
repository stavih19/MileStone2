//
// Created by stavih19 on 13/01/2020.
//

#ifndef MILESTONE2_SERVER_SIDE_H
#define MILESTONE2_SERVER_SIDE_H

#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <map>
#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;

#include "ClientHandler.h"

namespace server_side {
    class Server {
        virtual void start(int port, ClientHandler *c) = 0;

        virtual void stop() = 0;
    };
}


#endif //MILESTONE2_SERVER_SIDE_H