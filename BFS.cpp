//
// Created by Amit Malkan on 20/01/20.
//
using namespace std;
#include "BFS.h"
#include <search.h>
#include <iostream>



vector<double> BFS::getPath(State<double>* goal)
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

vector<double> BFS::search(Searchable<double>* searchable)
{
	queue<State<double> *> que;
	vector<State<double> *> visitedStates;
	vector<State<double>* >* neighbors;
	State<double>* currentState;
	que.push(searchable->getInitialState());
	visitedStates.push_back(searchable->getInitialState());
	while (!que.empty()) {
		currentState = que.front();
		if (currentState->equal(searchable->getGoalState())) {
			cout << "The number of nodes is: " << this->getNumberOfNodesEvaluated() << endl;
			this->increaeNumNodes();
			return getPath(currentState);
		}
		else {
			neighbors = searchable->getAllPossibleState2(currentState);
			que.pop();
			this->increaeNumNodes();
			for (State<double>* neighbor : *neighbors) {
				if (!checkForCir(visitedStates, neighbor)) {
					neighbor->setParent(currentState);
					neighbor->setCost(currentState->getCost());
					visitedStates.push_back(neighbor);
					que.push(neighbor);
				}
			}
		}
	}
	vector<double> ans;
	ans.push_back(-1);
	return ans;
}

int BFS::getNumberOfNodesEvaluated()
{
	return this->numOfNodes;
}

void BFS::increaeNumNodes()
{
	numOfNodes++;
}

bool BFS::checkForCir(vector<State<double> *> visitedVects, State<double>* curState)
{
	for (auto state : visitedVects) {
		if (curState->equal(state)) {
			return true;
		}
	}
	return false;
}


