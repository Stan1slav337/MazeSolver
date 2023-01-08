#pragma once

#include "MazeSolver.h"
#include "Maze.h"
#include "TreeNode.h"

class SearchAlgo 
{
public:
	SearchAlgo(class MazeSolver*);

protected:
	virtual void init() = 0;
	virtual void search() = 0;

	void createBlock(std::shared_ptr<TreeNode>, Utils::blockType);
	void createAnswer(std::shared_ptr<TreeNode>);
	std::shared_ptr<TreeNode> getRoot();
	bool isFinal(std::shared_ptr<TreeNode>);

	std::unique_ptr<class Maze> maze;
		
private:
	void initializeMaze(const int);
	void updateTree();
	std::shared_ptr<TreeNode> makeTree(Utils::point, std::shared_ptr<TreeNode>);
	void showMaze();

	friend class MazeSolver;
	class MazeSolver* visual;
	std::shared_ptr<TreeNode> root;
};
