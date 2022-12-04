#pragma once

#include <QtWidgets/QMainWindow>
#include "Utils.hpp"

class GridBlock: public QRect
{
public:
	GridBlock(int, int, int, int, Utils::blockType);

	static GridBlock createWallBlock(Utils::point, const int);
	static GridBlock createPathBlock(Utils::point, const int);
	static GridBlock createAnswBlock(Utils::point, const int);

	Utils::blockType type;
};

