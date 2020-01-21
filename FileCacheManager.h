//
// Created by stavih19 on 13/01/2020.
//

#ifndef MILESTONE2_FILECACHEMANAGER_H
#define MILESTONE2_FILECACHEMANAGER_H

#include "ServersInterfaces/CacheManager.h"
#include <fstream>
#include <vector>
#include <cstring>

class FileCacheManager : public CacheManager<string, string> {
private:
    unordered_map<string, string> problemSolutionMap = unordered_map<string, string>();
    string diskName = "diskFile";
public:
    bool isSolutionExist(string problem) override; // insert problem

    string getSolution(string problem) override; // return solution and insert problem

    void saveSolution(string problem, string solution) override; // insert problem

    vector<string> split(const string &str, const string &sep);
};

#endif //MILESTONE2_FILECACHEMANAGER_H