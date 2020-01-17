//
// Created by stavih19 on 14/01/2020.
//

#ifndef MILESTONE2_STRINGREVERSER_H
#define MILESTONE2_STRINGREVERSER_H

#include "ServersInterfaces/Solver.h"
#include <string>

using namespace std;

class StringReverser : public Solver {
public:
    string solve(string problem) override;
};

#endif //MILESTONE2_STRINGREVERSER_H