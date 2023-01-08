#include "DFS.h"

void DFS::init()
{
	stiva = {};
	stiva.push(getRoot());
}

void DFS::search()
{
	if (isFinal(stiva.top()))
	{
		createAnswer(stiva.top());
		return;
	}

	auto currNode = stiva.top();
	stiva.pop();
	createBlock(currNode, Utils::PATH);

	for (auto childNode : currNode->getChildren())
		stiva.push(childNode);
}