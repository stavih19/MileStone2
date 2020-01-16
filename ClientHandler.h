//
// Created by stavih19 on 13/01/2020.
//

#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H

#include <string>
#include "CacheManager.h"
#include "Solver.h"
#include <vector>

using namespace std;

class ClientHandler {
protected:
    CacheManager<string, string> *cacheManager{};
    Solver *solver{};
public:
    virtual vector<string> handleClient(vector<string> problems) = 0;
};


#endif //MILESTONE2_CLIENTHANDLER_H