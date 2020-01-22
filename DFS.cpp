//
// Created by Amit Malkan on 21/01/20.
//
using namespace std;
#include "DFS.h"
#include <search.h>
#include <iostream>

vector<double> DFS::getPath(State<double>* goal)
{
	vector<double> answer;
	vector<State<double>*> temp;

	// take the node and put into a vector
	while (goal->getParent() != nullptr) {
		temp.push_back(goal);
		goal = goal->getParent();
	}
	temp.push_back(goal);

	// reverse the order
	while (!temp.empty()) {
		answer.push_back(temp.front()->getState());
		temp.pop_back();
	}

	return answer;
}

vector<double> DFS::search(Searchable<double>* searchable) {
    vector<State<double> *> visitedStates;
    stack < State<double> *> stack;
    vector<State<double> *>* neighbors;
    State<double> *currentState;

    stack.push(searchable->getInitialState());

    while (!stack.empty()) {
        currentState = stack.top();
        stack.pop();
		this->increaeNumNodes();

        if (!checkForCir(visitedStates, currentState)) {
            visitedStates.push_back(currentState);
        }

        if (currentState->equal(searchable->getGoalState())) {
            cout << "num of nodes: " << this->getNumberOfNodesEvaluated() << endl;
            this->increaeNumNodes();
            return getPath(currentState);
        }

        neighbors = searchable->getAllPossibleState2(currentState);
        for (State<double> *neighbor : *neighbors) {
            if (!checkForCir(visitedStates, neighbor)) {
                neighbor->setParent(currentState);
                neighbor->setCost(currentState->getCost());
                stack.push(neighbor);
            }
        }
    }
	vector<double> ans;
	ans.push_back(-1);
	return ans;
}

int DFS::getNumberOfNodesEvaluated()
{
	return numOfNodes;
}

void DFS::increaeNumNodes()
{
	numOfNodes++;
}

bool DFS::checkForCir(vector<State<double> *> visitedVects, State<double> *curState) {

    for (auto state : visitedVects) {
        if (curState->equal(state)) {
            return true;
        }
    }
    return false;
}
