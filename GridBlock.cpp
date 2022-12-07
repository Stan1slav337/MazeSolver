#include "GridBlock.h"
#include "MazeSolver.h"

GridBlock::GridBlock(int x, int y, int width, int height, Utils::blockType type) : QRect(x, y, width, height), type(type) {}