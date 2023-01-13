#include "SearchAlgo.h"

SearchAlgo::SearchAlgo(MazeSolver* solver)
{
	visual = solver;
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
}

void SearchAlgo::updateTree()
{
	TreeNode::nrNodes++;
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

void SearchAlgo::showTree(std::shared_ptr<TreeNode> node)
{
	painter.begin(visual);
	pen.setColor(Qt::black);
	painter.setPen(pen);

	auto dx = WINDOW_WIDTH / maze->N;
	auto dy = WINDOW_HEIGHT / maze->N;
	auto rx = 0.75 * dx / 2;
	auto ry = 0.75 * dy / 2;
	auto [x, y] = node->getCords();

	QRect rect{ x * dx, y * dy + MENU_HEIGHT, dx, dy };
	painter.drawEllipse(QPointF(x * dx + dx / 2, y * dy + dy / 2 + MENU_HEIGHT), rx, ry);
	painter.drawText(rect, Qt::AlignVCenter | Qt::AlignHCenter, QString::number(node->getVal()));

	for (auto& child : node->getChildren())
	{
		auto [xCh, yCh] = child->getCords();
		int dirX = xCh == x ? 0 : xCh > x ? 1 : -1;
		int dirY = yCh == y ? 0 : yCh > y ? 1 : -1;

		painter.drawLine(QPointF(x * dx + dx / 2 + dirX * rx, y * dy + dy / 2 + MENU_HEIGHT + dirY * ry),
			QPointF(xCh * dx + dx / 2 - dirX * rx, yCh * dy + dy / 2 + MENU_HEIGHT - dirY * ry));
	}

	painter.end();

	for (auto& child : node->getChildren())
		showTree(child);
}

void SearchAlgo::showMaze()	
{
	painter.begin(visual);

	for (auto &block : maze->grid)
	{
		pen.setColor(Utils::colors.at(block.type));
		painter.setBrush(Utils::colors.at(block.type));
		painter.setPen(pen);
		painter.drawRect(block);
	}

	painter.end();

	showTree(root);
}
