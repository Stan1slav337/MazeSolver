#include "Maze.h"

Maze::Maze(const int LEN)
{
	N = LEN;

	generateBinaryGrid();
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
				if (binaryGrid[nextX + dirX][nextY + dirY] == 0)
					break;

				bool ok = true;
				for (auto [nextDir, nextDirCords] : Utils::moves)
				{
					auto [nextDirX, nextDirY] = nextDirCords;

					if (dirX == -nextDirX && dirY == -nextDirY)
						continue;

					if (binaryGrid[nextX + dirX + nextDirX][nextY + dirY + nextDirY] == 0)
						ok = false;
				}

				if (!ok)
					break;

				nextX += dirX, nextY += dirY;
				binaryGrid[nextX][nextY] = 0;
			}

			if (nextX != cordX || nextY != cordY)
				nodes.push({ nextX, nextY });
		}
	}

}
