#include "SearchAlgo.h"

SearchAlgo::SearchAlgo(MazeSolver* solver, bool isDijkstra) : visual(solver), hasDistances(isDijkstra)
{
}

void SearchAlgo::createBlock(std::shared_ptr<TreeNode> node, Utils::blockType type)
{
	auto [x, y] = node->getCords();
	auto [px, py] = node->getParent()->getCords();
	auto offsetX = x == px ? 0 : x - px > 0 ? 1 : -1;
	auto offsetY = y == py ? 0 : y - py > 0 ? 1 : -1;

	for (int i = 1; i <= node->getDistanceFromParent(); ++i)
		maze->addBlock({ px + offsetX * i, py + offsetY * i }, type);

	visual->update();
}

void SearchAlgo::createAnswer(std::shared_ptr<TreeNode> node)
{
	printConsole("Am găsit nodul țintă, se parcurg părinții nodului pentru a găsi calea de la start.\n\n");

	while (node != TreeNode::dummy)
	{
		createBlock(node, Utils::ANSW);
		node = node->getParent();
	}
}

void SearchAlgo::printConsole(QString str)
{
	visual->printConsole(str);
}

std::shared_ptr<TreeNode> SearchAlgo::getRoot()
{
	return root;
}

bool SearchAlgo::isFinal(std::shared_ptr<TreeNode> node)
{
	return maze->end == node->getCords();
}

QString SearchAlgo::getStringFromNode(std::shared_ptr<TreeNode> node)
{
	auto [x, y] = node->getCords();

	if (hasDistances)
	{
		if (visual->getShowTree())
			return QString("{%1, %2}").arg(QString::number(node->getVal()), QString::number(node->getDistanceFromParent()));
		return QString("{%1, %2, %3}").arg(QString::number(y), QString::number(x), QString::number(node->getParent() == TreeNode::dummy ? 0 : node->getDistanceFromParent()));
	}

	if (visual->getShowTree())
		return QString::number(node->getVal());

	return QString("{%1, %2}").arg(QString::number(y), QString::number(x));
}

void SearchAlgo::initializeMaze(const int LEN)
{
	maze = std::make_unique<Maze>(LEN);

	for (int y = 0; y < LEN; ++y)
		for (int x = 0; x < LEN; ++x)
			if (maze->binaryGrid[y][x])
				maze->addBlock({ x, y }, Utils::WALL);

	maze->addBlock(maze->end, Utils::PATH);
	endIdx = maze->grid.size();
}

void SearchAlgo::updateTree()
{
	TreeNode::nrNodes = 0;
	root = makeTree(Utils::point{ 1, 1 }, TreeNode::dummy);
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
			auto [offsetX, offsetY] = dirCords;

			if (hasDistances)
				while (maze->binaryGrid[cordY + offsetY + dirY][cordX + offsetX + dirX] == 0 &&
					maze->binaryGrid[cordY + offsetY + dirX][cordX + offsetX + dirY] == 1 &&
					maze->binaryGrid[cordY + offsetY - dirX][cordX + offsetX - dirY] == 1)
					offsetX += dirX, offsetY += dirY;

			auto childCords = Utils::point{ cordX + offsetX, cordY + offsetY };

			if (parent == TreeNode::dummy || childCords != parent->getCords())
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

	auto dx = DELTA;
	auto dy = DELTA;
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

const QColor SearchAlgo::getBlockColor(GridBlock& block) const
{
	if (Utils::PATH == block.type && (block == maze->grid.back() || block == maze->grid[endIdx - 1]))
		return ACTIVE_BLOCK;

	return Utils::colors.at(block.type);
}

void SearchAlgo::showMaze()
{
	painter.begin(visual);

	for (auto& block : maze->grid)
	{
		auto color = getBlockColor(block);
		pen.setColor(color);
		painter.setBrush(color);
		painter.setPen(pen);
		painter.drawRect(block);
	}

	painter.end();

	if (visual->getShowTree())
		showTree(root);
}