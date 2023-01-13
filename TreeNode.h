#pragma once

#include <vector>
#include <memory>
#include "Utils.hpp"

class TreeNode
{
public:
	TreeNode(Utils::point cords, std::shared_ptr<TreeNode> parent) : cords(cords), parent(parent), val(nrNodes++) {}

	void addChild(std::shared_ptr<TreeNode>);
	std::vector<std::shared_ptr<TreeNode>> getChildren() const;
	std::shared_ptr<TreeNode> getParent() const;
	Utils::point getCords() const;
	int getVal() const;

	static int nrNodes;

private:

	int val;
	Utils::point cords;
	std::shared_ptr<TreeNode> parent;
	std::vector<std::shared_ptr<TreeNode>> children;
};

