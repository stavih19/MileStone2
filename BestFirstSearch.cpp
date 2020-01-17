//
// Created by stavih19 on 17/01/2020.
//

#include "BestFirstSearch.h"
#include "State.h"
#include <algorithm>

template<class T>
vector<string> BestFirstSearch<T>::search(Searchable<T> searchable) {
    vector<string> answer;
    State<T> n;
    State<T> goalState = searchable.getGoalState();
    list<State<T>> successors;
    vector<State<T>> openHeap;
    vector<State<T>> closeHeap = {};

    // initial open & cloase heaps
    openHeap.push_back(searchable.getInitialState());
    make_heap(openHeap.begin(), openHeap.end());
    // get into the while loop
    while (openHeap.size() != 0) {
        n = openHeap.front(); // taking the best node from open
        increaeNumNodes();

        pop_heap(openHeap.begin(), openHeap.end()); // pop_heap(openHeap.begin(), openHeap.end());
        openHeap.pop_back(); // ???
        closeHeap.push_back(n);

        // in case we arrived to the goal
        if (n.equal(&goalState)) {
            openHeap.clear(); // make the while loop to stop
        } else {
            successors = searchable.getAllPossibleState(n);
            for (State<T> s:successors) {
                increaeNumNodes();
                // in case the node is not in non of the lists
                if (!openHeap.at(s) && !closeHeap.at(s)) {
                    s.set(&n);
                    openHeap.push_back(s);
                } else if ((s.cameFrom->cost + s.cost) > (n.cost + s.cost)) { // in case we can improve the cost
                    if (!openHeap.at(s)) { // in case its not in open list
                        openHeap.push_back(s);
                    } else { // in case it is
                        s.setCost(n.cost + s.cost);
                        s.setParent(n);
                    }
                }
            }
        }
        make_heap(openHeap.begin(), openHeap.end()); // reordering the heap
    }

    answer = getPath(&n);
    return answer;
}

template<class T>
int BestFirstSearch<T>::getNumberOfNodesEvaluated() {
    return numOfNodes;
}

template<class T>
vector<string> BestFirstSearch<T>::getPath(State<T> *goal) {
    vector<string> answer;
    vector<string> temp;

    // take the node and put into a vector
    while (goal->cameFrom != nullptr) {
        temp.push_back(goal);
        goal = goal->cameFrom;
    }
    temp.push_back(goal);

    // reverse the order
    while (!temp.empty()) {
        answer.push_back(temp.front());
        temp.pop_back();
    }

    return answer;
}

template<class T>
void BestFirstSearch<T>::increaeNumNodes() {
    numOfNodes++;
}
