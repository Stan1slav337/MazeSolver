#include "SearchAlgo.h"

SearchAlgo::SearchAlgo(MazeSolver* solver)
{
	visual = solver;

	initializeMaze(DEFAULT_N);
	root = makeTree(Utils::point {1, 1}, nullptr);
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

std::shared_ptr<TreeNode> SearchAlgo::getRoot()
{
	return root;
}

void SearchAlgo::initializeMaze(const int LEN)
{
	maze = std::make_unique<Maze>(LEN);

	for (int y = 0; y < LEN; ++y)
		for (int x = 0; x < LEN; ++x)
			if (maze->binaryGrid[y][x])
				maze->addBlock({ x, y }, Utils::WALL);

	maze->addBlock(maze->start, Utils::PATH);
	maze->addBlock(maze->end  , Utils::PATH);

	toProcess = 2;

	visual->update();
}

std::shared_ptr<TreeNode> SearchAlgo::makeTree(Utils::point cords, std::shared_ptr<TreeNode> parent)
{
	auto [cordX, cordY] = cords;
	auto node = std::make_shared<TreeNode>(cords);

	for (auto [dir, dirCords] : Utils::moves)
	{
		auto [dirX, dirY] = dirCords;

		if (maze->binaryGrid[cordY + dirY][cordX + dirX] == 0)
		{
			auto childCords = Utils::point{ cordX + dirX, cordY + dirY };

			if (parent == nullptr || childCords != parent->getCords())
				node->addChild(makeTree(childCords, node));
		}
	}

	return node;
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
