#pragma once

#include <vector>
#include "MazeSolver.h"
#include "Maze.h"

class SearchAlgo 
{
public:
	SearchAlgo() = default;
	SearchAlgo(class MazeSolver*);
	~SearchAlgo() = default;

protected:
	std::unique_ptr<class Maze> maze;
		
private:
	void initializeMaze();
	void showMaze();

	friend class MazeSolver;
	class MazeSolver* visual;
};
