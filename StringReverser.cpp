//
// Created by stavih19 on 14/01/2020.
//

#include "StringReverser.h"

string StringReverser::solve(string problem) {
    int len = problem.length();
    int index = len - 1;
    string solution;

    for (int i = 0; i < len; i++) {
        solution += problem[index - i];
    }

    return solution;
}