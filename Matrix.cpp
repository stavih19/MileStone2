//
// Created by stavih19 on 17/01/2020.
//

#include "Matrix.h"

State<double> *Matrix::getInitialState() {
    auto *firstCell = new State<double>(1, nullptr);
    firstCell->setCost(0);

    return firstCell;
}

State<double> *Matrix::getGoalState() {
    auto goalCell = new State<double>(n * m, nullptr);
    goalCell->setCost(0);

    return goalCell;
}

list<State<double> *> *Matrix::getAllPossibleState(State<double> *state) {
    auto successors = new list<State<double> *>();

    CellMatrix *point = convertHashToPoint((int)state->getState());
    if (isUpWall(*point)) { // get the upper cell
        double newHash = state->getState() - n;
        auto temp = new State<double>(newHash, state);
        CellMatrix *newPoint = convertHashToPoint((int) newHash);
        temp->setCost(newPoint->getWeight());
        successors->push_back(temp);
    }
    if (isRightWall(*point)) {
        double newHash = state->getState() + 1;
        auto temp = new State<double>(newHash, state);
        CellMatrix *newPoint = convertHashToPoint((int) newHash);
        temp->setCost(newPoint->getWeight());
        successors->push_back(temp);
    }
    if (isDownWall(*point)) {
        double newHash = state->getState() + n;
        auto temp = new State<double>(newHash, state);
        CellMatrix *newPoint = convertHashToPoint((int) newHash);
        temp->setCost(newPoint->getWeight());
        successors->push_back(temp);
    }
    if (isLeftWall(*point)) {
        double newHash = state->getState() - 1;
        auto *temp = new State<double>(newHash, state);
        CellMatrix *newPoint = convertHashToPoint((int) newHash);
        temp->setCost(newPoint->getWeight());
        successors->push_back(temp);
    }

    return successors;
}

CellMatrix *Matrix::convertHashToPoint(int hash) {
    int i = (hash - 1) / n;
    int j = (hash - 1) % m;
    double weight = matrix->at(i)->at(j)->getWeight();

    return new CellMatrix(i, j, weight);
}

double Matrix::convertPointToHash(CellMatrix point) {
    return ((point.getI() + 1) * m + (point.getJ() + 1));
}

bool Matrix::isWall(CellMatrix point) {
    bool answer = false;
    CellMatrix *cell = matrix->at(point.getI())->at(point.getJ());
    if (cell->getWeight() == -1) {
        answer = true;
    }

    return answer;
}