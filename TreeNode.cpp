#include "TreeNode.h"

void TreeNode::addChild(std::shared_ptr<TreeNode> child)
{
	children.push_back(child);
}

std::vector<std::shared_ptr<TreeNode>> TreeNode::getChildren() const
{
	return children;
}

Utils::point TreeNode::getCords()
{
	return cords;
}
