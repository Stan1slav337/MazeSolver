#include "DFS.h"

void DFS::init()
{
	stack = {};
	stack.push(getRoot());
}

void DFS::search()
{
	auto currNode = stack.top();
	stack.pop();
	createBlock(currNode, Utils::PATH);

	if (isFinal(currNode))
	{
		createAnswer(currNode);
		return;
	}

	for (auto childNode : currNode->getChildren())
		stack.push(childNode);
}