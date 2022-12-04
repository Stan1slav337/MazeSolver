#include "GridBlock.h"
#include "MazeSolver.h"

GridBlock::GridBlock(int x, int y, int width, int height, Utils::blockType type) : QRect(x, y, width, height), type(type) {}

GridBlock GridBlock::createWallBlock(Utils::point cords, const int LEN)
{
	auto dx = WINDOW_WIDTH / LEN;
	auto dy = WINDOW_HEIGHT / LEN;
	auto [x, y] = cords;

	MazeSolver::delay();

	return GridBlock(x * dx, y * dy + MENU_HEIGHT, dx, dy, Utils::WALL);
}

GridBlock GridBlock::createPathBlock(Utils::point cords, const int LEN)
{
	auto dx = WINDOW_WIDTH / LEN;
	auto dy = WINDOW_HEIGHT / LEN;
	auto [x, y] = cords;

	MazeSolver::delay();

	return GridBlock(x * dx + 1, y * dy + 1 + MENU_HEIGHT, dx - 1, dy - 1, Utils::PATH);
}