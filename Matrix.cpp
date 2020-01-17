//
// Created by stavih19 on 17/01/2020.
//

#include "Matrix.h"

State<CellMatrix> Matrix::getInitialState() {
    State<CellMatrix> firstCell = State<CellMatrix>(0, nullptr);
    firstCell.setCost(0);

    return firstCell;
}

State<CellMatrix> Matrix::getGoalState() {
    State<CellMatrix> goalCell = State<CellMatrix>(0, nullptr);
    goalCell.setState(n * m);
    goalCell.setParent(nullptr);
    goalCell.setCost(0);

    return goalCell;
}

list<State<struct CellMatrix>> Matrix::getAllPossibleState(State<CellMatrix> state) {
    list<State<struct CellMatrix>> successors = list<State<CellMatrix>>();

    CellMatrix *point = convertHashToPoint(state.getState());
    if (isUpWall(*point)) { // get the upper cell
        double newHash = state.getState() - n;
        State<CellMatrix> temp = State<CellMatrix>(newHash, &state);
        temp.setCost(point->getWeight());
        successors.push_back(temp);
    } else if (isRightWall(*point)) {
        double newHash = state.getState() + 1;
        State<CellMatrix> temp = State<CellMatrix>(newHash, &state);
        temp.setCost(point->getWeight());
        successors.push_back(temp);
    } else if (isDownWall(*point)) {
        double newHash = state.getState() + n;
        State<CellMatrix> temp = State<CellMatrix>(newHash, &state);
        temp.setCost(point->getWeight());
        successors.push_back(temp);
    } else if (isLeftWall(*point)) {
        double newHash = state.getState() - 1;
        State<CellMatrix> temp = State<CellMatrix>(newHash, &state);
        temp.setCost(point->getWeight());
        successors.push_back(temp);
    }

    return successors;
}

CellMatrix *Matrix::convertHashToPoint(int hash) {
    int i = (hash + 1) / n;
    int j = (hash - 1) % m;
    double weight = matrix.at(j).at(i).getWeight();

    return new CellMatrix(i, j, weight);
}

double Matrix::convertPointToHash(CellMatrix point) {
    return ((point.getI() + 1) * m + (point.getJ() + 1));
}

bool Matrix::isWall(CellMatrix point) {
    bool answer = false;
    CellMatrix cell = matrix.at(point.getJ()).at(point.getI());
    if (cell.getWeight() == -1) {
        answer = true;
    }

    return answer;
}