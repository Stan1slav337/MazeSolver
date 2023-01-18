#pragma once

#include <queue>
#include "SearchAlgo.h"

class Dijkstra : public SearchAlgo
{
public:
	Dijkstra(class MazeSolver* solver) : SearchAlgo(solver, true) {}

	void init();
	bool search();
	void printStart();
	void printStep();
	void printStructure();

private:
	struct comparator
	{
		bool operator()(const std::shared_ptr<TreeNode> nodeA, const std::shared_ptr<TreeNode> nodeB) const
		{
			return nodeA->getDistanceFromParent() > nodeB->getDistanceFromParent();
		}
	};

	std::priority_queue< std::shared_ptr<TreeNode>, std::vector< std::shared_ptr<TreeNode>>, comparator> priority_queue;
};