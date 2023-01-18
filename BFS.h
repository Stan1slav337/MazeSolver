#pragma once

#include "SearchAlgo.h"
#include <queue>

class BFS : public SearchAlgo
{
public:
	BFS(class MazeSolver* solver) : SearchAlgo(solver) {}

	void init();
	bool search();
	void printStart();
	void printStep();
	void printStructure();

private:
	std::queue<std::shared_ptr<TreeNode>> queue;
};

