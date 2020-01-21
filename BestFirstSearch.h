//
// Created by stavih19 on 17/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "Matrix.h"
#include "State.h"
#include <utility>
#include <algorithm>
#include <queue>

class BestFirstSearch : public Searcher<double> {
private:
    int numOfNodes{};

    struct Comper {
        bool operator()(State<double> *state1, State<double> *state2) {
            return state1->getCost() > state2->getCost();
        }
    };

    vector<double> getPath(State<double> *goal);

    void increaeNumNodes();

    State<double> *getInList(State<double> *state, list<State<double> *> list);

public:
    vector<double> search(Searchable<double> *searchable) override;

    int getNumberOfNodesEvaluated() override;
};

#endif //MILESTONE2_BESTFIRSTSEARCH_H