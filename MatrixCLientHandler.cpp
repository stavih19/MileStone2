//
// Created by stavih19 on 20/01/2020.
//

#include "MatrixCLientHandler.h"

vector<string> MatrixCLientHandler::handleClient(vector<string> problems) {
    vector<string> answer;
    Matrix *matrix;

    string matrixFormat = formatMatrix(&problems);
    if (cacheManager->isSolutionExist(matrixFormat)) {
        answer.push_back(cacheManager->getSolution(matrixFormat));
    } else {
        matrix = getVectors(&problems);
        string solution = solver->solve(matrix);
        cacheManager->saveSolution(matrixFormat, solution);
        answer.push_back(solution);
    }

    return answer;
}

Matrix *MatrixCLientHandler::getVectors(vector<string> *vectors) {
    Matrix *matrix = nullptr;
    vector<string> tempRow;
    auto *matVectors = new vector<vector<CellMatrix *> *>();
    string temp = vectors->at(0);

    int rows = (int) vectors->size() - 2;
    int columns = split(temp, ",").size();

    for (int i = 0; i < rows; i++) {
        tempRow = split(vectors->at(i), ",");
        matVectors->push_back(new vector<CellMatrix *>());
        for (int j = 0; j < columns; j++) {
            matVectors->at(i)->push_back(new CellMatrix(i, j, atof(tempRow.at(j).c_str())));
        }
    }

    matrix = new Matrix(matVectors);
    return matrix;
}

string MatrixCLientHandler::formatMatrix(vector<string> *matrix) {
    string answer;

    for (string vector:*matrix) {
        answer += vector + "$";
    }
    answer = answer.substr(0, answer.length() - 1);

    return answer;
}

vector<string> MatrixCLientHandler::split(const string &str, const string &sep) {
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