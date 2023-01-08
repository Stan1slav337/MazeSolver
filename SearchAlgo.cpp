#include "SearchAlgo.h"

SearchAlgo::SearchAlgo(MazeSolver* solver)
{
	visual = solver;

	initializeMaze(DEFAULT_N);
}

void SearchAlgo::createBlock(std::shared_ptr<TreeNode> node, Utils::blockType type)
{
	auto cords = node->getCords();
	maze->addBlock(cords, type);
	visual->update();
}

void SearchAlgo::createAnswer(std::shared_ptr<TreeNode> node)
{
	while (node != nullptr)
	{
		createBlock(node, Utils::ANSW);
		node = node->getParent();
	}
}

std::shared_ptr<TreeNode> SearchAlgo::getRoot()
{
	return root;
}

bool SearchAlgo::isFinal(std::shared_ptr<TreeNode> node)
{
	return maze->end == node->getCords();
}

void SearchAlgo::initializeMaze(const int LEN)
{
	maze = std::make_unique<Maze>(LEN);

	for (int y = 0; y < LEN; ++y)
		for (int x = 0; x < LEN; ++x)
			if (maze->binaryGrid[y][x])
				maze->addBlock({ x, y }, Utils::WALL);

	maze->addBlock(maze->end  , Utils::PATH);

	visual->update();
	updateTree();
}

void SearchAlgo::updateTree()
{
	root = makeTree(Utils::point{ 1, 1 }, nullptr);
}

std::shared_ptr<TreeNode> SearchAlgo::makeTree(Utils::point cords, std::shared_ptr<TreeNode> parent)
{
	auto [cordX, cordY] = cords;
	auto node = std::make_shared<TreeNode>(cords, parent);

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

	for (auto &block : maze->grid)
	{
		pen.setColor(Utils::colors.at(block.type));
		painter.setBrush(Utils::colors.at(block.type));
		painter.setPen(pen);
		painter.drawRect(block);
	}
}
