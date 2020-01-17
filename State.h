//
// Created by stavih19 on 16/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

template<class T>
class State {
protected:
    T state;
    double cost{};
    State<T> *cameFrom;

    int test;
public:
    State(T stateN) : state(stateN), cameFrom(nullptr) {}

    virtual void set(State<T> *cameFromN) {
        cameFrom = cameFromN;
    }

    virtual bool equal(State<T> *other) {

    }
};

#endif //MILESTONE2_STATE_H
