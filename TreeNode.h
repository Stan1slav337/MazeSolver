#pragma once

#include <vector>
#include <memory>
#include "Utils.hpp"

class TreeNode
{
public:
	TreeNode(Utils::point cords) : cords(cords) {}

	void addChild(std::shared_ptr<TreeNode>);
	std::vector<std::shared_ptr<TreeNode>> getChildren() const;
	Utils::point getCords();

private:

	Utils::point cords;
	std::vector<std::shared_ptr<TreeNode>> children;
};

