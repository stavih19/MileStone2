//
// Created by stavih19 on 20/01/2020.
//

#ifndef MILESTONE2_MATRIXCLIENTHANDLER_H
#define MILESTONE2_MATRIXCLIENTHANDLER_H

#include "ServersInterfaces/ClientHandler.h"
#include "CellMatrix.h"
#include "ServersInterfaces/Solver.h"
#include "PathInMatrix.h"
#include "MatrixCacheManager.h"
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class MatrixCLientHandler : public ClientHandler {
private:
    MatrixCacheManager *cacheManager;
    PathInMatrix *solver;

    string formatMatrix(vector<string> *matrix);

    Matrix *getVectors(vector<string>* matrix);

    vector<string> split(const string &str, const string &sep);

public:
    MatrixCLientHandler() {
        cacheManager = new MatrixCacheManager();
        solver = new PathInMatrix();
    }

    vector<string> handleClient(vector<string> problems) override;
};


#endif //MILESTONE2_MATRIXCLIENTHANDLER_H
