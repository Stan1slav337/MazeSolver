#include "SearchAlgo.h"

SearchAlgo::SearchAlgo(MazeSolver* solver)
{
	visual = solver;
	maze = std::unique_ptr<Maze>(new Maze());

	initializeMaze();
}

void SearchAlgo::initializeMaze()
{
	auto dx = WINDOW_WIDTH / DEFAULT_N;
	auto dy = WINDOW_HEIGHT / DEFAULT_N;

	for(int y = 0; y < DEFAULT_N; ++y)
		for (int x = 0; x < DEFAULT_N; ++x)
		{
			if (maze->binaryGrid[y][x])
				maze->grid.push_back(GridBlock(
					x * dx,
					y * dy + MENU_HEIGHT,
					dx,
					dy
				));
		}   

	GridBlock start(dx, dy + MENU_HEIGHT, dx, dy);
	start.type = 2;
	maze->grid.push_back(start);

	visual->update();
}

void SearchAlgo::showMaze()	
{
	QPainter painter(visual);
	QPen pen;

	for (auto &block : maze->grid)
	{
		pen.setColor(block.type == 1 ? BLOCK_COLOR : VISITED_BLOCK);
		painter.setBrush(block.type == 1 ? BLOCK_COLOR : VISITED_BLOCK);
		painter.setPen(pen);

		painter.drawRect(block);
	}
}
