//
// Created by stavih19 on 15/01/2020.
//

#include <fstream>
#include <vector>
#include <cstring>
#include "FileCacheManager.h"

bool FileCacheManager::isSolutionExist(string problem) {
    string solution;
    bool answer = false;

    solution = problemSolutionMap[problem];

    if (!solution.empty()) {
        answer = true;
    }

    return answer;
}

string FileCacheManager::getSolution(string problem) {
    string solution, line;
    vector<string> pair;

    ifstream fp(diskName);
    if (!fp.is_open()) { exit(1); }
    while (getline(fp, line)) {
        pair = split(line, "|");
        if (pair.at(0) == problem) {
            solution = pair.at(1);
            problemSolutionMap.insert(std::pair<string, string>(pair.at(0), pair.at(1)));
        }
    }

    return solution;
}

void FileCacheManager::saveSolution(string problem, string solution) {
    string input;
    pair<string, string> temp;

    ofstream fp(diskName);
    if (!fp.is_open()) { exit(1); }

    for (auto temp:problemSolutionMap) {
        input += temp.first + "|" + temp.second;
        fp << input << '\n';
    }
}

vector<string> FileCacheManager::split(const string &str, const string &sep) {
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    std::vector<std::string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != nullptr) {
        arr.push_back(current);
        current = strtok(nullptr, sep.c_str());
    }

    return arr;
}
