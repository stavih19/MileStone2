//
// Created by stavih19 on 16/01/2020.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include <string>
#include <vector>
#include <list>
#include "State.h"

using namespace std;

template<class T>
class Searchable {
public:
    virtual State<T> *getInitialState() = 0;

    virtual State<T> *getGoalState() = 0;

    virtual list<State<T> *> *getAllPossibleState(State<T> *state) = 0;
};


#endif //MILESTONE2_SEARCHABLE_H