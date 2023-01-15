#include "Dijkstra.h"

void Dijkstra::init()
{
	priority_queue = {};
	priority_queue.push(getRoot());
}

void Dijkstra::search()
{
	if (priority_queue.empty())
		return;

	printStep();
	auto currNode = priority_queue.top();
	priority_queue.pop();
	createBlock(currNode, Utils::PATH);

	if (isFinal(currNode))
	{
		createAnswer(currNode);
		return;
	}

	for (auto childNode : currNode->getChildren())
		priority_queue.push(childNode);

	printStructure();
}

void Dijkstra::printStart()
{
	printConsole("Algoritmul lui Dijkstra începe de la rădăcină⁠ și similar căutării în lățime adaugă nodurile vecine într-o coadă.\n");
	printConsole("Nodurile sunt introduse păstrând o ordine crescătoarea a distanțelor dintre nod și părintele acestuia.\n");
	printConsole("Pe lângă valoarea nodurilor din coadă, acestea mai au păstrate și o variabilă pentru distanță.\n");
	printConsole("Inițial se adaugă nodul de start în coadă.\n");
}

void Dijkstra::printStep()
{
	printConsole("Extragem nodul din începutul cozii: " + getStringFromNode(priority_queue.top()) + " și introducem copii acestuia în coadă\n");
}

void Dijkstra::printStructure()
{
	auto printQueue(priority_queue);
	printConsole("Coada curentă: [");

	if (!printQueue.empty())
	{
		printConsole(getStringFromNode(printQueue.top()));
		printQueue.pop();
	}

	while (!printQueue.empty())
	{
		printConsole(", " + getStringFromNode(printQueue.top()));
		printQueue.pop();
	}

	printConsole("]\n\n");
}