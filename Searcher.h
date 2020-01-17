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
protected:
    int numOfNodes;
public:
    vector<string> search(Searchable<T> searchable);

    int getNumberOfNodesEvaluated();
};

#endif //MILESTONE2_SEARCHER_H
