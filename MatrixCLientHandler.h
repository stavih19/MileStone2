//
// Created by stavih19 on 20/01/2020.
//

#ifndef MILESTONE2_MATRIXCLIENTHANDLER_H
#define MILESTONE2_MATRIXCLIENTHANDLER_H

#include "ServersInterfaces/ClientHandler.h"
#include "vector"
#include "CellMatrix.h"
#include "ServersInterfaces/Solver.h"
#include <cstring>
#include <string>

using namespace std;

class MatrixCLientHandler : public ClientHandler {
private:
    vector<string> split(std::string str, std::string sep);

public:
    vector<string> handleClient(vector<string> problems) override;
};


#endif //MILESTONE2_MATRIXCLIENTHANDLER_H
