#pragma once

#include "MazeSolver.h"
#include "Maze.h"
#include "Utils.hpp"

class SearchAlgo 
{
public:
	SearchAlgo() = default;
	SearchAlgo(class MazeSolver*);
	~SearchAlgo() = default;

protected:
	void createBlock(Utils::point, Utils::blockType);

	std::unique_ptr<class Maze> maze;
		
private:
	void initializeMaze(const int);
	void showMaze();

	friend class MazeSolver;
	class MazeSolver* visual;
	Utils::SleepSimulator sleep;
};
