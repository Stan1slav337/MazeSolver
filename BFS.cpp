#include "BFS.h"

void BFS::init()
{
	queue = {};
	queue.push(getRoot());
}

void BFS::search()
{
	auto currNode = queue.front();
	queue.pop();
	createBlock(currNode, Utils::PATH);

	if (isFinal(currNode))
	{
		createAnswer(currNode);
		return;
	}

	for (auto childNode : currNode->getChildren())
		queue.push(childNode);
}