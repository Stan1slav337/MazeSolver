#pragma once

#include <QtWidgets/QMainWindow>

class GridBlock: public QRect
{
public:
	GridBlock(int, int, int, int);

	int type;
};

