#pragma once

#include "MazeSolver.h"
#include "Maze.h"
#include "TreeNode.h"
#include "GridBlock.h"

class SearchAlgo 
{
public:
	SearchAlgo(class MazeSolver*, bool = false);
	void finalizeAlgo();

protected:
	virtual void init() = 0;
	virtual bool search() = 0;
	virtual void printStart() = 0;
	virtual void printStep() = 0;
	virtual void printStructure() = 0;

	void createBlock(std::shared_ptr<TreeNode>, Utils::blockType);
	void createAnswer(std::shared_ptr<TreeNode>);
	void printConsole(QString);
	std::shared_ptr<TreeNode> getRoot();
	bool isFinal(std::shared_ptr<TreeNode>);
	QString getStringFromNode(std::shared_ptr<TreeNode>);

	std::unique_ptr<class Maze> maze;
		
private:
	void initializeMaze(const int);
	void updateTree();
	std::shared_ptr<TreeNode> makeTree(Utils::point, std::shared_ptr<TreeNode>);
	void showTree(std::shared_ptr<TreeNode>);
	const QColor getBlockColor(GridBlock&) const;
	void showMaze();

	friend class MazeSolver;
	class MazeSolver* visual;
	std::shared_ptr<TreeNode> root;
	bool hasDistances;
	int endIdx;

	QPainter painter;
	QPen pen;
};
