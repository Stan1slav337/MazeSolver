#include "TreeNode.h"

void TreeNode::addChild(std::shared_ptr<TreeNode> child)
{
	children.push_back(child);
}

std::vector<std::shared_ptr<TreeNode>> TreeNode::getChildren() const
{
	return children;
}

std::shared_ptr<TreeNode> TreeNode::getParent() const
{
	return parent;
}

Utils::point TreeNode::getCords() const
{
	return cords;
}
