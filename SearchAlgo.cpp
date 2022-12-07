#include "SearchAlgo.h"

SearchAlgo::SearchAlgo(MazeSolver* solver)
{
	visual = solver;

	initializeMaze(DEFAULT_N);
}

void SearchAlgo::createBlock(Utils::point cords, Utils::blockType type)
{
	maze->addBlock(cords, type);

	if (!byStep)
	{
		sleep.sleep(Utils::toSleep.at(maze->N));
		visual->delay();
		visual->update();
	}
}

void SearchAlgo::initializeMaze(const int LEN)
{
	maze = std::make_unique<Maze>(LEN);

	auto dx = WINDOW_WIDTH / LEN;
	auto dy = WINDOW_HEIGHT / LEN;

	for (int y = 0; y < LEN; ++y)
		for (int x = 0; x < LEN; ++x)
			if (maze->binaryGrid[y][x])
				maze->addBlock({ x, y }, Utils::WALL);

	maze->addBlock(maze->start, Utils::PATH);
	maze->addBlock(maze->end  , Utils::PATH);

	toProcess = 2;

	visual->update();
}

void SearchAlgo::showMaze()	
{
	QPainter painter(visual);
	QPen pen;

	int proccesed = 0;

	for (auto &block : maze->grid)
	{
		pen.setColor(Utils::colors.at(block.type));
		painter.setBrush(Utils::colors.at(block.type));
		painter.setPen(pen);
		painter.drawRect(block);

		if (block.type == Utils::PATH) 
		{
			if (byStep && MazeSolver::isRunning && proccesed == toProcess)
			{
				toProcess++;
				break;
			}
			proccesed++;
		}
	}
}
