//
// Created by stavih19 on 17/01/2020.
//

#include "BestFirstSearch.h"

vector<double> BestFirstSearch::search(Searchable<double> *searchable) {
    vector<double> answer;
    list<State<double> *> *successors;
    list<State<double> *> openList;
    list<State<double> *> closeHeap;
    priority_queue<State<double> *, vector<State<double> *>, Comper> pq;

    State<double> *n = searchable->getInitialState();
    auto goalState = searchable->getGoalState();

    // initial open & cloase heaps
    openList.push_back(n);
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
                increaeNumNodes();
                // in case the node is not in non of the lists
                if ((!isInList(s, openList)) && (!isInList(s, closeHeap))) {
                    s->setParent(n);
                    pq.push(s);
                    openList.push_back(s);
                } else if ((s->getParent()->getCost() + s->getCost()) >
                           (n->getCost() + s->getCost())) { // in case there is shorter path
                    if (!isInList(s, openList)) { // in case s isnt in OPEN
                        pq.push(s);
                        openList.push_back(s);
                    } else { // update its cost
                        s->setCost(n->getCost() + s->getCost());
                        s->setParent(n);
                    }
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
        answer.push_back(temp.front()->getState());
        temp.pop_back();
    }

    return answer;
}

int BestFirstSearch::getNumberOfNodesEvaluated() {
    return numOfNodes;
}

bool BestFirstSearch::isInList(State<double> *state, list<State<double> *> list) {
    bool answer = false;

    for (State<double> *temp:list)
        if (temp->getState() == state->getState()) {
            answer = true;
        }

    return answer;
}
