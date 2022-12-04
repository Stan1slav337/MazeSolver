#include "SearchAlgo.h"

SearchAlgo::SearchAlgo(MazeSolver* solver)
{
	visual = solver;

	initializeMaze(DEFAULT_N);
}

void SearchAlgo::initializeMaze(const int LEN)
{
	maze = std::make_unique<Maze>(LEN);

	auto dx = WINDOW_WIDTH / LEN;
	auto dy = WINDOW_HEIGHT / LEN;

	for(int y = 0; y < LEN; ++y)
		for (int x = 0; x < LEN; ++x)
			if (maze->binaryGrid[y][x])
				maze->grid.push_back(GridBlock::createWallBlock({ x, y }, LEN));

	maze->grid.push_back(GridBlock::createPathBlock({1, 1}, LEN));

	visual->update();
}

void SearchAlgo::showMaze()	
{
	QPainter painter(visual);
	QPen pen;

	for (auto &block : maze->grid)
	{
		pen.setColor(block.type == Utils::WALL ? BLOCK_COLOR : VISITED_BLOCK);
		painter.setBrush(block.type == Utils::WALL ? BLOCK_COLOR : VISITED_BLOCK);
		painter.setPen(pen);

		painter.drawRect(block);
	}
}
