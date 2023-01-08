#pragma once

#include <vector>
#include <memory>
#include "Utils.hpp"

class TreeNode
{
public:
	TreeNode(Utils::point cords, std::shared_ptr<TreeNode> parent) : cords(cords), parent(parent) {}

	void addChild(std::shared_ptr<TreeNode>);
	std::vector<std::shared_ptr<TreeNode>> getChildren() const;
	std::shared_ptr<TreeNode> getParent() const;
	Utils::point getCords() const;

private:

	Utils::point cords;
	std::shared_ptr<TreeNode> parent;
	std::vector<std::shared_ptr<TreeNode>> children;
};

