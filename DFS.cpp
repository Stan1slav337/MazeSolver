#include "DFS.h"

void DFS::search()
{
	back(maze->start);
}

bool DFS::back(Utils::point cords)
{
	auto [cordX, cordY] = cords;
	maze->binaryGrid[cordY][cordX] = 1;

	maze->grid.push_back(GridBlock::createPathBlock(cords, maze->N));
	visual->update();

	bool found = cords == maze->end;

	for (auto [dir, dirCords] : Utils::moves)
	{
		auto [dirX, dirY] = dirCords;

		if (maze->binaryGrid[cordY + dirY][cordX + dirX] == 0)
			found = found || back({ cordX + dirX, cordY + dirY });
	}

	if (found) 
	{
		maze->grid.push_back(GridBlock::createAnswBlock(cords, maze->N));
		visual->update();
	}

	return found;
}
