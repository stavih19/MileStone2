//
// Created by stavih19 on 17/01/2020.
//

#ifndef MILESTONE2_BASICSTATE_H
#define MILESTONE2_BASICSTATE_H

#include "State.h"

template<class T>
class BasicState : public State<T> {
    void set(State<T> *cameFromN) override {

    }

    virtual bool equal(State<T> other) override {

    }
};


#endif //MILESTONE2_BASICSTATE_H
