#pragma once

#include <QPainter>
#include <map>
#include <queue>
#include <chrono>
#include <random>

constexpr auto MENU_HEIGHT   = 25;
constexpr auto DELTA	     = 42;
constexpr auto DEFAULT_N     = 15;
constexpr auto BLOCK_COLOR   = Qt::darkCyan;
constexpr auto ACTIVE_BLOCK  = Qt::yellow;
constexpr auto VISITED_BLOCK = Qt::cyan;
constexpr auto ANSWER_BLOCK  = Qt::green;

class Utils 
{
public:
	using point = std::pair<int, int>;

	enum blockType
	{
		WALL,
		PATH,
		ANSW
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

	const static inline std::map<blockType, const QColor> colors = {
		{WALL, BLOCK_COLOR  },
		{PATH, VISITED_BLOCK},
		{ANSW, ANSWER_BLOCK }
	};

	const static inline std::map<blockType, int> offsets = {
		{WALL, 0},
		{PATH, 1},
		{ANSW, 1}
	};

	static int getRandom(int l, int r) 
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		auto rnd = std::default_random_engine(seed);

		return l + rnd() % (r - l + 1);
	}
};