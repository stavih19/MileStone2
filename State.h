//
// Created by stavih19 on 16/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <string>

using namespace std;

template<class T>
class State {
protected:
    T state;
    double cost{};
    State<T> *cameFrom;
public:
    State(double stateN, State<T>* camefromN) : state(stateN), cameFrom(camefromN) {}

    bool equal(State<T> *other) {
        return (state == other->state);
    }

    void setState(double stateN) {
        state = stateN;
    }

    void setParent(State<T> *cameFromN) {
        cameFrom = cameFromN;
    }

    void setCost(double costN) {
        cost = costN;
    }

    double getState() {
        return state;
    }

    State<T> *getParent() {
        return cameFrom;
    }

    double getCost() {
        return cost;
    }
};

#endif //MILESTONE2_STATE_H