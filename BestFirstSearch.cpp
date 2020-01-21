//
// Created by stavih19 on 17/01/2020.
//

#include "BestFirstSearch.h"

vector<double> BestFirstSearch::search(Searchable<double> *searchable) {
    vector<double> answer;
    list < State < double > * > *successors;
    list < State < double > * > openList;
    list < State < double > * > closeHeap;
    priority_queue < State < double > *, vector < State < double > * >, Comper > pq;

    State<double> *n = searchable->getInitialState();
    auto goalState = searchable->getGoalState();

    // initial open & cloase heaps
    openList.push_back(n);
    n->setCost(n->getCost());
    pq.push(n);
    // get into the while loop
    while (!openList.empty()) {
        increaeNumNodes();

        n = pq.top(); // taking the best node from open
        pq.pop(); // pop_heap(openHeap.begin(), openHeap.end());
        openList.remove(n);
        //openHeap.pop_back(); // ???
        closeHeap.push_back(n);

        // in case we arrived to the goal
        if ((*n).equal(goalState)) {
            openList.clear(); // make the while loop to stop
        } else {
            successors = searchable->getAllPossibleState(n);
            for (State<double> *s:*successors) {
                //increaeNumNodes();
                State<double> *stateInOpen = getInList(s, openList);
                State<double> *stateInClose = getInList(s, closeHeap);
                // in case the node is not in non of the lists
                if ((stateInOpen == nullptr) && (stateInClose == nullptr)) {
                    s->setParent(n);
                    s->setCost(s->getCost());
                    pq.push(s);
                    openList.push_back(s);
                } else if (stateInOpen != nullptr) {
                    if (s->getParent()->getCost() + s->getCost() < stateInOpen->getCost()) {
                        s->setCost(s->getCost());
                        pq.push(s);
                        openList.push_back(s);
                    }
                } else {
                    s->setCost(n->getCost() + s->getCost());
                    s->setParent(n);
                }
            }
        }
    }
    answer = getPath(n);
    return answer;
}

void BestFirstSearch::increaeNumNodes() {
    numOfNodes++;
}

vector<double> BestFirstSearch::getPath(State<double> *goal) {
    vector<double> answer;
    vector<State<double> *> temp;

    // take the node and put into a vector
    while (goal->getParent() != nullptr) {
        temp.push_back(goal);
        goal = goal->getParent();
    }
    temp.push_back(goal);

    // reverse the order
    while (!temp.empty()) {
        answer.push_back(temp.back()->getState());
        temp.pop_back();
    }

    return answer;
}

int BestFirstSearch::getNumberOfNodesEvaluated() {
    return numOfNodes;
}

State<double> *BestFirstSearch::getInList(State<double> *state, list<State<double> *> list) {
    State<double> *answer = nullptr;

    for (State<double> *temp:list)
        if (temp->getState() == state->getState()) {
            answer = temp;
        }

    return answer;
}
