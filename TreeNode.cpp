#include "TreeNode.h"

int TreeNode::nrNodes = 0;
std::shared_ptr<TreeNode> TreeNode::dummy = std::make_shared<TreeNode>(Utils::point{ 0, 1 }, nullptr);

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

int TreeNode::getVal() const
{
	return val;
}

int TreeNode::getDistanceFromParent() const
{
	auto [x, y] = cords;
	auto [px, py] = parent->getCords();

	return std::abs(x - px) + std::abs(y - py);
}