#pragma once

#include "SearchAlgo.h"
#include "GridBlock.h"

class Maze
{
public:
	Maze(const int);

	int getLen() const;
	void addBlock(Utils::point, Utils::blockType);

private:
	friend class SearchAlgo;

	void generateBinaryGrid();
	Utils::point findRandomEnd();

	int N;
	std::vector<GridBlock> grid;
	std::vector<std::vector<bool>> binaryGrid;

	Utils::point start, end;
};