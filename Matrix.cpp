//
// Created by stavih19 on 17/01/2020.
//

#include "Matrix.h"

State<PointMatrix> Matrix::getInitialState() {
    State<PointMatrix> firstCell = State<PointMatrix>(0, nullptr);
    firstCell.setCost(0);

    return firstCell;
}

State<PointMatrix> Matrix::getGoalState() {
    State<PointMatrix> goalCell = State<PointMatrix>(0, nullptr);
    goalCell.setState(n * m);
    goalCell.setParent(nullptr);
    goalCell.setCost(0);

    return goalCell;
}

list<State<struct PointMatrix>> Matrix::getAllPossibleState(State<PointMatrix> state) {
    list<State<struct PointMatrix>> successors = list<State<PointMatrix>>();

    PointMatrix *point = convertHashToPoint(state.getState());
    if (isUpWall(*point)) { // get the upper cell
        double newHash = state.getState() - n;
        State<PointMatrix> temp = State<PointMatrix>(newHash, &state);
        temp.setCost(point->getWeight());
        successors.push_back(temp);
    } else if (isRightWall(*point)) {
        double newHash = state.getState() + 1;
        State<PointMatrix> temp = State<PointMatrix>(newHash, &state);
        temp.setCost(point->getWeight());
        successors.push_back(temp);
    } else if (isDownWall(*point)) {
        double newHash = state.getState() + n;
        State<PointMatrix> temp = State<PointMatrix>(newHash, &state);
        temp.setCost(point->getWeight());
        successors.push_back(temp);
    } else if (isLeftWall(*point)) {
        double newHash = state.getState() - 1;
        State<PointMatrix> temp = State<PointMatrix>(newHash, &state);
        temp.setCost(point->getWeight());
        successors.push_back(temp);
    }

    return successors;
}

PointMatrix *Matrix::convertHashToPoint(int hash) {
    int i = (hash + 1) / n;
    int j = (hash - 1) % m;
    double weight = matrix.at(j).at(i).getWeight();

    return new PointMatrix(i, j, weight);
}

double Matrix::convertPointToHash(PointMatrix point) {
    return ((point.getI() + 1) * m + (point.getJ() + 1));
}

bool Matrix::isWall(PointMatrix point) {
    bool answer = false;
    PointMatrix cell = matrix.at(point.getJ()).at(point.getI());
    if (cell.getWeight() == -1) {
        answer = true;
    }

    return answer;
}