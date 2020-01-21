//
// Created by stavih19 on 20/01/2020.
//

#include "PathInMatrix.h"

string PathInMatrix::solve(Matrix *problem) {
    string answer;
    matrix = problem;

    BestFirstSearch bfs = BestFirstSearch();
    vector<double> solutions = bfs.search(problem);

    answer = convetToDirections(solutions);

    return answer;
}

string PathInMatrix::convetToDirections(vector<double> answer) {
    string vector;
    double current = answer.at(0);
    double next;

    for (int i = 1; i < answer.size(); ++i) {
        next = answer.at(i);
        vector += getDir(current, next) + ",";
        current = next;
    }

    vector = vector.substr(0, vector.size() - 1);
    return (vector += '\n');
}

string PathInMatrix::getDir(double source, double dest) {
    string answer;
    int n = matrix->getN();

    if (source - n == dest) {
        answer = "up";
    } else if (source + 1 == dest) {
        answer = "right";
    } else if (source + n == dest) {
        answer = "down";
    } else if (source - 1 == dest) {
        answer = "left";
    }

    return answer;
}
