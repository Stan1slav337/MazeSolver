#include "GridBlock.h"
#include "MazeSolver.h"

const GridBlock GridBlock::dummy{ 0, 0, 0, 0, Utils::WALL };

GridBlock::GridBlock(int x, int y, int width, int height, Utils::blockType type) : QRect(x, y, width, height), type(type) {}