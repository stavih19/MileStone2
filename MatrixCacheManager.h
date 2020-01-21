//
// Created by stavih19 on 21/01/2020.
//

#ifndef MILESTONE2_MATRIXCACHEMANAGER_H
#define MILESTONE2_MATRIXCACHEMANAGER_H

#include "ServersInterfaces/CacheManager.h"
#include "Matrix.h"
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

class MatrixCacheManager : public CacheManager<string, string> {
private:
    unordered_map<string, string> problemSolutionMap = unordered_map<string, string>();
    string diskName = "diskFile";

    vector<string> split(const string &str, const string &sep);

public:
    bool isSolutionExist(string input) override;

    string getSolution(string input) override;

    void saveSolution(string input, string output) override;
};


#endif //MILESTONE2_MATRIXCACHEMANAGER_H
