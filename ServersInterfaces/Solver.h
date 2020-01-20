//
// Created by stavih19 on 14/01/2020.
//

#ifndef MILESTONE2_SOLVER_H
#define MILESTONE2_SOLVER_H

#include <string>

using namespace std;

template <class P,class S>
class Solver {
public:
    virtual S solve(P problem) = 0;
};


#endif //MILESTONE2_SOLVER_H