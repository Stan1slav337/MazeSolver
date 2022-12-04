#pragma once

#include "SearchAlgo.h"
#include "GridBlock.h"

class Maze
{
public:
	Maze(const int);

private:
	friend class SearchAlgo;

	void generateBinaryGrid();

	int N;
	std::vector<GridBlock> grid;
	std::vector<std::vector<bool>> binaryGrid;
};