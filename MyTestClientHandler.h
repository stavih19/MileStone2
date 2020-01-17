//
// Created by stavih19 on 13/01/2020.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H

#include "ServersInterfaces/ClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

class MyTestClientHandler : public ClientHandler {
public:
    MyTestClientHandler() {
        cacheManager = new FileCacheManager();
        solver = new StringReverser();
    }

    vector<string> handleClient(vector<string> problems) override;
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H