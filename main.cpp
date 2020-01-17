//
// Created by stavih19 on 15/01/2020.
//

#include "ServersInterfaces/boot.h"
#include "Searcher.h"
#include "Matrix.h"
#include "PointMatrix.h"
#include "BestFirstSearch.h"

using namespace boot;

int main(int argc, const char *args[]) {
    Searcher<BestFirstSearch<PointMatrix>> bfs = BestFirstSearch<PointMatrix>();



    boot::Main::main(argc, args);
    this_thread::sleep_for(chrono::milliseconds(120000));

    return 0;
}
