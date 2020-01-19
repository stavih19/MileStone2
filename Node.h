//
// Created by stavih19 on 19/01/2020.
//

#ifndef MILESTONE2_NODE_H
#define MILESTONE2_NODE_H

template<class T>
class Node {
private:
    double value;
    T *obj;
public:
    Node(double valueN, T *objN) {
        value = valueN;
        obj = objN;
    }

    double getValue() {
        return value;
    }

    T *getObj() {
        return obj;
    }
};

#endif //MILESTONE2_NODE_H
