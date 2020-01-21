//
// Created by stavih19 on 21/01/2020.
//

#include "MatrixCacheManager.h"

bool MatrixCacheManager::isSolutionExist(string input) {
    string solution;
    bool answer = false;

    solution = problemSolutionMap[input];

    if (!solution.empty()) {
        answer = true;
    }

    return answer;
}

string MatrixCacheManager::getSolution(string problem) {
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

void MatrixCacheManager::saveSolution(string problem, string solution) {
    string input;

    problemSolutionMap[problem] = solution;

    ofstream fp(diskName);
    if (!fp.is_open()) { exit(1); }

    for (auto temp:problemSolutionMap) {
        input += temp.first + "|" + temp.second;
        fp << input << '\n';
        input = "";
    }
}

vector<string> MatrixCacheManager::split(const string &str, const string &sep) {
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
