//
// Created by Amit Malkan on 20/01/20.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H

#include "Searcher.h"
#include "Matrix.h"
#include "State.h"
#include <utility>
#include <algorithm>
#include <queue>

template<class T>
class BFS : public Searcher<T> {
private:
    int numOfNodes{};
    vector<double> getPath(State<T> *goal);
public:
    vector<double> search(Searchable<T> *searchable) override;

    int getNumberOfNodesEvaluated() override;

    void increaeNumNodes();

    bool checkForCir(vector<State<T> *> visitedVects, State<T> *curState);
};


#endif //MILESTONE2_BFS_H
