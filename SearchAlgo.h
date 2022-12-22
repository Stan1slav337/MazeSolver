#pragma once

#include "MazeSolver.h"
#include "Maze.h"
#include "TreeNode.h"

class SearchAlgo 
{
public:
	SearchAlgo() = default;
	SearchAlgo(class MazeSolver*);
	~SearchAlgo() = default;

protected:
	void createBlock(Utils::point, Utils::blockType);
	std::shared_ptr<TreeNode> getRoot();

	std::unique_ptr<class Maze> maze;
		
private:
	void initializeMaze(const int);
	std::shared_ptr<TreeNode> makeTree(Utils::point, std::shared_ptr<TreeNode>);
	void showMaze();

	friend class MazeSolver;
	class MazeSolver* visual;
	Utils::SleepSimulator sleep;
	std::shared_ptr<TreeNode> root;

	int toProcess;
	bool byStep = false;
};
