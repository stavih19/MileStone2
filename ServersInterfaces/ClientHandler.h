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

//template<class P, class S>
class ClientHandler {
protected:
    //CacheManager<string, string> *cacheManager;
    //Solver<string, string> *solver;
public:
    virtual vector<string> handleClient(vector<string> problems) = 0;
};

#endif //MILESTONE2_CLIENTHANDLER_H