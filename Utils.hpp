#pragma once

#include <QPainter>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <chrono>
#include <random>

constexpr auto MENU_HEIGHT = 25;
constexpr auto WINDOW_WIDTH = 500;
constexpr auto WINDOW_HEIGHT = 500;
constexpr auto DEFAULT_N = 25;
constexpr auto BLOCK_COLOR = Qt::darkCyan;
constexpr auto VISITED_BLOCK = Qt::cyan;

class Utils 
{
public:
	using point = std::pair<int, int>;

	enum blockType
	{
		WALL,
		PATH
	};

	enum direction
	{
		LEFT, RIGHT, UP, DOWN
	};

	struct move
	{
		move(direction dir, int dx, int dy) : dir(dir), dx(dx), dy(dy) {}
		direction dir;
		int dx, dy;
	};

	const static inline std::map<const direction, const point> moves = {
		{LEFT,  {-1,   0}},
		{RIGHT, { 1,   0}},
		{UP,    { 0,  -1}},
		{DOWN,  { 0,   1}}
	};

	static int getRandom(int l, int r) 
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		auto rnd = std::default_random_engine(seed);

		return l + rnd() % (r - l + 1);
	}
};