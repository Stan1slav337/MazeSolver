#pragma once

#include <QtWidgets/QMainWindow>
#include "Utils.hpp"

class GridBlock: public QRect
{
public:
	GridBlock(int, int, int, int, Utils::blockType);

	static const GridBlock dummy;

	Utils::blockType type;
};

