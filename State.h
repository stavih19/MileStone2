//
// Created by stavih19 on 16/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

template<class T>
class State {
private:
    T state;
    double cost{};
    State<T> *cameFrom;
public:
    State(T stateN) : state(stateN), cameFrom(nullptr) {}

    virtual bool equal(State<T> other) = 0;
};

#endif //MILESTONE2_STATE_H
