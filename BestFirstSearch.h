//
// Created by stavih19 on 17/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"

template<class T>
class BestFirstSearch : public Searcher<T> {
private:
    int numOfNodes{};

    vector<string> getPath(State<T> *goal);

    void increaeNumNodes();
public:
    vector<string> search(Searchable<T> searchable) override;

    int getNumberOfNodesEvaluated() override;
};

#endif //MILESTONE2_BESTFIRSTSEARCH_H