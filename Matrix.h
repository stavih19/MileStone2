//
// Created by stavih19 on 17/01/2020.
//

#ifndef MILESTONE2_MATRIX_H
#define MILESTONE2_MATRIX_H

#include <utility>
#include "Searchable.h"
#include "PointMatrix.h"

class Matrix : public Searchable<PointMatrix> {
private:
    int n{}, m{};
    vector<vector<PointMatrix>> matrix;

    PointMatrix *convertHashToPoint(int hash);

    double convertPointToHash(PointMatrix point);

    bool isUpWall(PointMatrix point) {
        if (point.getI() != 0) {
            return !isWall(point);
        }
        return false;
    }

    bool isRightWall(PointMatrix point) {
        if (point.getJ() != m) {
            return !isWall(point);
        }
        return false;
    }

    bool isDownWall(PointMatrix point) {
        if (point.getI() != n) {
            return !isWall(point);
        }
        return false;
    }

    bool isLeftWall(PointMatrix point) {
        if (point.getJ() != 0) {
            return !isWall(point);
        }
        return false;
    }

    bool isWall(PointMatrix point);
public:
    Matrix(vector<vector<PointMatrix>> matrixN, int n, int m) {
        matrix = std::move(matrixN);
        n = matrix.size();
        m = matrix.at(0).size();
    }

    State<PointMatrix> getInitialState() override;

    State<PointMatrix> getGoalState() override;

    list<State<struct PointMatrix>> getAllPossibleState(State<PointMatrix> state) override;
};


#endif //MILESTONE2_MATRIX_H