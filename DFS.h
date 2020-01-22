//
// Created by Amit Malkan on 21/01/20.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H
#include "Searcher.h"
#include "Matrix.h"
#include "State.h"
#include <utility>
#include <algorithm>
#include <queue>

template<class T>
class DFS : public Searcher<T> {
private:
    int numOfNodes{};
    vector<double> getPath(State<T> *goal);
public:
    vector<double> search(Searchable<T> *searchable) override;

    int getNumberOfNodesEvaluated() override;

    void increaeNumNodes();

    bool checkForCir(vector<State<T>*> visitedVects, State<T>* curState);
};


#endif //MILESTONE2_DFS_H
