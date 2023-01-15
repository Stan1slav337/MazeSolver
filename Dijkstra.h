#pragma once

#include "SearchAlgo.h"

class Dijkstra: public SearchAlgo
{
public:
	Dijkstra(class MazeSolver* solver) : SearchAlgo(solver, true) {}

	void init();
	void search();
	void printStart();
	void printStep();
	void printStructure();

private:

};

