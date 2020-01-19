//
// Created by stavih19 on 19/01/2020.
//

#ifndef MILESTONE2_PRIORITYQUEUE_H
#define MILESTONE2_PRIORITYQUEUE_H

#include "Node.h"

template<class T>
class PriorityQueue {
    Node<T *> *arr;
    int empty;
    int max;
public:
    PriorityQueue(int number) {
        arr[number];
        bzero(arr, number);
        empty = 0;
        max = number;
    }

    void insert(double parameter, T *obj);

    T *getTop();

    void popTop();

    void removeObj(T *obj);
};

template<class T>
void PriorityQueue<T>::insert(double parameter, T *obj) {
    arr[empty] = new Node<T *>(parameter, obj);

    int indexParent = empty;
    int indexSun = empty;

    if (indexSun % 2 == 0) {
        indexParent = empty - 1;
        indexParent /= 2;
    }
    Node<T *> parent = arr[indexParent];
    while (parent.getValue() < parameter) {
        Node<T> *temp = parent;
        arr[indexParent] = arr[indexSun];
        arr[indexSun] = temp;

        indexSun = indexParent;
        if (indexSun % 2 == 0) {
            indexParent = indexParent - 1;
            indexParent /= 2;
        }
        parent = arr[indexParent];
    }
}

template<class T>
T *PriorityQueue<T>::getTop() {
    return (arr[0].getObj());
}

template<class T>
void PriorityQueue<T>::popTop() {
    Node<T> rightSun;
    Node<T> leftSun;
    int indexParent = 0;
    bool flag = true;

    if (max == 1) {
        arr[0] = '\0';
    } else if (max == 2) {
        arr[0] = arr[1];
        arr[1] = '\0';
    } else if (max == 3) {
        if (arr[1].getValue() > arr[2].getValue()) {
            arr[0] = arr[1];
            arr[1] = arr[2];
        } else {
            arr[0] = arr[2];
        }
        arr[2] = '\0';
    }

    while (flag) {
        if (indexParent * 2 > (empty - 1)) {
            flag = false;
        } else {

        }
    }
}


#endif //MILESTONE2_PRIORITYQUEUE_H
