//
// Created by stavih19 on 15/01/2020.
//

#include "ServersInterfaces/boot.h"
#include "CellMatrix.h"
#include "BestFirstSearch.h"
#include "Matrix.h"
#include <time.h>

using namespace boot;

int main(int argc, const char *args[]) {
    vector<vector<CellMatrix *> *> *matrixes[5];

    auto *mat = new vector<vector<CellMatrix *> *>();
    mat->push_back(new vector<CellMatrix *>());
    mat->push_back(new vector<CellMatrix *>());
    mat->push_back(new vector<CellMatrix *>());
    mat->at(0)->push_back(new CellMatrix(0, 0, 0));
    mat->at(0)->push_back(new CellMatrix(1, 0, 3));
    mat->at(0)->push_back(new CellMatrix(2, 0, 5));
    mat->at(1)->push_back(new CellMatrix(0, 1, 0));
    mat->at(1)->push_back(new CellMatrix(1, 1, 0));
    mat->at(1)->push_back(new CellMatrix(2, 1, 0));
    mat->at(2)->push_back(new CellMatrix(0, 2, 2));
    mat->at(2)->push_back(new CellMatrix(1, 2, 4));
    mat->at(2)->push_back(new CellMatrix(2, 2, 0));

    srand(time(NULL));
    int random;

    BestFirstSearch bfs = BestFirstSearch();

    for (int k = 1; k <= 5; k++) {
        auto *matrixRows = new vector<vector<CellMatrix *> *>();
        for (int j = 0; j < (k * 10); j++) {
            auto *column = new vector<CellMatrix *>();
            for (int i = 0; i < (k * 10); i++) {
                random = rand() % 100 + 1;
                column->push_back(new CellMatrix(i, j, random));
            }
            matrixRows->push_back(column);
        }
        matrixes[k - 1] = matrixRows;
    }

    auto *objMatrix = new Matrix(matrixes[0]);
    vector<double> solutions = bfs.search(objMatrix);
    cout << to_string(bfs.getNumberOfNodesEvaluated()) << endl;

    boot::Main::main(argc, args);
    this_thread::sleep_for(chrono::milliseconds(120000));

    return 0;
}
