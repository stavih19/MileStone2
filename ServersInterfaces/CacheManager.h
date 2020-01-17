//
// Created by stavih19 on 13/01/2020.
//

#ifndef MILESTONE2_CACHEMANAGER_H
#define MILESTONE2_CACHEMANAGER_H

#include <string>
#include <unordered_map>

using namespace std;
template<class P, class S>
class CacheManager {
public:
    virtual bool isSolutionExist(P input) = 0; // insert problem

    virtual string getSolution(P input) = 0; // return solution and insert problem

    virtual void saveSolution(P input, S output) = 0; // insert problem
};

#endif //MILESTONE2_CACHEMANAGER_H