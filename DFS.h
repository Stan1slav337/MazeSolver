#pragma once

#include "SearchAlgo.h"

class DFS : public SearchAlgo
{
public:
	void search();

private:
	bool back(Utils::point);

};

