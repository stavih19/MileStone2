//
// Created by stavih19 on 20/01/2020.
//

#ifndef MILESTONE2_PATHINMATRIX_H
#define MILESTONE2_PATHINMATRIX_H

#include "ServersInterfaces/Solver.h"
#include "BestFirstSearch.h"
#include "Matrix.h"
#include "CellMatrix.h"

class PathInMatrix : public Solver<Matrix *, string> {
private:
    Matrix* matrix{};

    string convetToDirections(vector<double> answer);

    string getDir(double source, double dest);

public:
    string solve(Matrix *problem) override;
};


#endif //MILESTONE2_PATHINMATRIX_H
