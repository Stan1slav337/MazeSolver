#pragma once

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <chrono>
#include <random>

class Utils 
{
public:
	using point = std::pair<int, int>;

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