//
// Created by stavih19 on 17/01/2020.
//

#ifndef MILESTONE2_CELLMATRIX_H
#define MILESTONE2_CELLMATRIX_H

#include "State.h"

class CellMatrix {
private:
    int i, j;
    double weight;
public:
    CellMatrix() {
        i = -1;
        j = -1;
        weight = -1;
    }

    CellMatrix(int iN, int jN, double weightN) : i(iN), j(jN), weight(weightN) {}

    void setI(int iN) { i = iN; }

    void setJ(int jN) { j = jN; }

    void setWeight(double weightN) { weight = weightN; }

    int getI() { return i; }

    int getJ() { return j; }

    double getWeight() { return weight; }
};

#endif //MILESTONE2_CELLMATRIX_H
