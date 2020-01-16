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

template <class T>
class Searchable {
    State<T> getInitialState();

    State<T> getGoalState();

    list<State<T>> getAllPossibleState(State<T> state);
};

template<class T>
State<T> Searchable<T>::getInitialState() {
    return State<T>(T());
}

template<class T>
State<T> Searchable<T>::getGoalState() {
    return State<T>(T());
}

template<class T>
list<State<T>> Searchable<T>::getAllPossibleState(State<T> state) {
    return list<State<T>>();
}


#endif //MILESTONE2_SEARCHABLE_H
