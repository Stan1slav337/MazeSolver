#include "BFS.h"

void BFS::init()
{
	queue = {};
	queue.push(getRoot());
}

bool BFS::search()
{
	if (queue.empty())
		return false;

	printStep();
	auto currNode = queue.front();
	queue.pop();
	createBlock(currNode, Utils::PATH);

	if (isFinal(currNode))
	{
		createAnswer(currNode);
		return true;
	}

	for (auto childNode : currNode->getChildren())
		queue.push(childNode);

	printStructure();

	return true;
}

void BFS::printStart()
{
	printConsole("Căutarea în lățime începe de la rădăcină⁠ și se explorează nodurile mai întâi vecine acestuia, înainte de a trece la vecinii de pe nivelul următor.\n");
	printConsole("Pentru a păstra ordinea nodurilor vecine, se folosește o coadă.\n");
	printConsole("Inițial se adaugă nodul de start în coadă.\n");
}

void BFS::printStep()
{
	printConsole("Extragem nodul din începutul cozii: " + getStringFromNode(queue.front()) + " și introducem copii acestuia în coadă\n");
}

void BFS::printStructure()
{
	auto printQueue(queue);
	printConsole("Coada curentă: [");

	if (!printQueue.empty())
	{
		printConsole(getStringFromNode(printQueue.front()));
		printQueue.pop();
	}

	while (!printQueue.empty())
	{
		printConsole(", " + getStringFromNode(printQueue.front()));
		printQueue.pop();
	}

	printConsole("]\n\n");
}