//
// Created by stavih19 on 16/01/2020.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H

#include "Searchable.h"
#include <vector>
#include <string>

using namespace std;

template<class T>
class Searcher {
    virtual vector<T> search(Searchable<T>* searchable) = 0;

    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //MILESTONE2_SEARCHER_H