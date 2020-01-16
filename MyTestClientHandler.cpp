//
// Created by stavih19 on 13/01/2020.
//

#include <iostream>
#include "MyTestClientHandler.h"

vector<string> MyTestClientHandler::handleClient(vector<string> problems) {
    vector<string> solutions;
    string solution;

    for (const auto &problem:problems) {
        if (cacheManager->isSolutionExist(problem)) {
            solutions.push_back(cacheManager->getSolution(problem));
        } else {
            solution = solver->solve(problem);
            cacheManager->saveSolution(problem, solution);
            solutions.push_back(solution);
        }
    }

    return solutions;
}