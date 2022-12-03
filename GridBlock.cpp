#include "GridBlock.h"

GridBlock::GridBlock(int x, int y, int width, int height) : QRect(x, y, width, height)
{
	type = 1;
}
