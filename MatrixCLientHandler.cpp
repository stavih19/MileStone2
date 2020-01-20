//
// Created by stavih19 on 20/01/2020.
//

#include "MatrixCLientHandler.h"
#include "PathInMatrix.h"

vector<string> MatrixCLientHandler::handleClient(vector<string> problems) {
    vector<string> answer;
    auto *matrixVectors = new vector<vector<CellMatrix *> *>();

    int rows = (int)problems.size() - 2;
    vector<string> tempRow = split(problems.at(0), ",");
    int columns = tempRow.size();

    for (int i = 0; i < rows; i++) {
        tempRow = split(problems.at(i), ",");
        matrixVectors->push_back(new vector<CellMatrix *>());
        for (int j = 0; j < columns; ++j) {
            double weight = atof(tempRow.at(j).c_str());
            matrixVectors->at(i)->push_back(new CellMatrix(i, j, weight));
        }
    }

    auto *matrix = new Matrix(matrixVectors);
    PathInMatrix solver = PathInMatrix();
    answer.push_back(solver.solve(matrix));

    return answer;
}

vector<string> MatrixCLientHandler::split(std::string str, std::string sep) {
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    std::vector<std::string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != nullptr) {
        arr.push_back(current);
        current = strtok(nullptr, sep.c_str());
    }
    return arr;
}