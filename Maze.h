#pragma once

#include <vector>
#include "SearchAlgo.h"
#include "GridBlock.h"

class Maze
{
public:
	Maze();

private:
	friend class SearchAlgo;
	std::vector<GridBlock> grid;
	std::vector<std::vector<bool>> binaryGrid;
};