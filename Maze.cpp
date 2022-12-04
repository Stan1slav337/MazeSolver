#include "Maze.h"
#include <iostream>

Maze::Maze(const int LEN)
{
	N = LEN;

	start = { 1, 1 }; 
	generateBinaryGrid();
	end = findRandomEnd();
}

void Maze::generateBinaryGrid()
{
	binaryGrid.resize(N, std::vector<bool>(N, 1));

	binaryGrid[1][1] = 0;

	std::queue<Utils::point> nodes;
	nodes.push({ 1, 1 });

	while (!nodes.empty())
	{
		auto [cordX, cordY] = nodes.front(); nodes.pop();

		std::map<const Utils::direction, int> maxMoves = {
			{Utils::LEFT,  cordX - 1    },
			{Utils::RIGHT, N - cordX - 2},
			{Utils::UP,    cordY - 1    },
			{Utils::DOWN,  N - cordY - 2}
		};

		for (auto [dir, dirCords] : Utils::moves)
		{
			auto [dirX, dirY] = dirCords;
			int toMove = Utils::getRandom(0, maxMoves[dir]);

			int nextX = cordX, nextY = cordY;
			for (int i = 0; i < toMove; ++i)
			{
				if (binaryGrid[nextY + dirY][nextX + dirX] == 0)
					break;

				bool ok = true;
				for (auto [nextDir, nextDirCords] : Utils::moves)
				{
					auto [nextDirX, nextDirY] = nextDirCords;

					if (dirX == -nextDirX && dirY == -nextDirY)
						continue;

					if (binaryGrid[nextY + dirY + nextDirY][nextX + dirX + nextDirX] == 0)
						ok = false;
				}

				if (!ok)
					break;

				nextX += dirX, nextY += dirY;
				binaryGrid[nextY][nextX] = 0;
			}

			if (nextX != cordX || nextY != cordY)
				nodes.push({ nextX, nextY });
		}
	}

}

Utils::point Maze::findRandomEnd()
{
	do {
		int randomX = Utils::getRandom(1, N - 2),
			randomY = Utils::getRandom(1, N - 2);

		if (binaryGrid[randomY][randomX] == 1)
			continue;

		int cnt = 0;

		for (auto [dir, dirCords] : Utils::moves)
		{
			auto [dirX, dirY] = dirCords;
			
			if (binaryGrid[randomY + dirY][randomX + dirX] == 0)
				cnt++;
		}

		if (cnt == 1)
			return { randomX, randomY };


	} while (true);

	return Utils::point();
}
