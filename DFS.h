#pragma once

#include "SearchAlgo.h"
#include <stack>

class DFS : public SearchAlgo
{
public:
	DFS(class MazeSolver* solver) : SearchAlgo(solver) {}

	void init();
	void search();

private:
	std::stack<std::shared_ptr<TreeNode>> stack;
};

