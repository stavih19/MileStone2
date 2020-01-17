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
    vector<vector<CellMatrix *>> matrixes[5];

    srand(time(NULL));
    int random;

    BestFirstSearch<CellMatrix> bfs = BestFirstSearch<CellMatrix>();

    for (int k = 1; k <= 5; k++) {
        vector<vector<CellMatrix *>> matrix = matrixes[k];
        for (int j = 0; j < (k * 10); j++) {
            vector<CellMatrix *> column;
            for (int i = 0; i < (k * 10); i++) {
                random = rand() % 100 + 1;
                column.at(i) = new CellMatrix(i, j, random);
            }
        }
    }

    Searchable<CellMatrix> objMatrix = Matrix(matrixes[0]);
    //Matrix objMatrix = Matrix(matrixes[0]);
    vector<string> solutions = bfs.search(objMatrix);

    boot::Main::main(argc, args);
    this_thread::sleep_for(chrono::milliseconds(120000));

    return 0;
}
