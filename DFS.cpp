#include <ranges>
#include "DFS.h"

void DFS::init()
{
	stack = {};
	stack.push(getRoot());
}

void DFS::search()
{
	if (stack.empty())
		return;

	printStep();
	auto currNode = stack.top();
	stack.pop();
	createBlock(currNode, Utils::PATH);

	if (isFinal(currNode))
	{
		createAnswer(currNode);
		return;
	}

	for (auto childNode : currNode->getChildren() | std::views::reverse)
		stack.push(childNode);

	printStructure();
}

void DFS::printStart()
{
	printConsole("Căutarea în adâncime începe de la rădăcină⁠ și se explorează cât mai mult posibil de-a lungul fiecărei ramuri înainte de a face pași înapoi.\n");
	printConsole("Pentru a păstra nodurile în care trebuie să ne întoarcem după ce ajungem la capătul unei ramuri, ne vom folosi de o stivă.\n");
	printConsole("Inițial se adaugă nodul de start în stivă.\n");
}

void DFS::printStep()
{
	printConsole("Extragem nodul din vârful stivei: " + getStringFromNode(stack.top()) + " și introducem copii acestuia în stivă\n");
}

void DFS::printStructure()
{
	auto printStack(stack);
	printConsole("Stiva curentă: [");

	if (!printStack.empty())
	{
		printConsole(getStringFromNode(printStack.top()));
		printStack.pop();
	}

	while (!printStack.empty())
	{
		printConsole(", " + getStringFromNode(printStack.top()));
		printStack.pop();
	}

	printConsole("]\n\n");
}