#pragma once
#include <string>
#include <vector>
#include "StringManip.h"

class Grid {
public:
	enum Direction { DOWN, RIGHT, DOWN_LEFT, DOWN_RIGHT };
	enum Operation {ADD, MULTIPLY, SUBTRACT, DIVIDE};
	StringManip StringManipulator;
	std::vector<std::vector<std::string>> grid1;
	void inputString(std::string& input, int lengthOfGrid);

	int MultiplyInDirection(Direction Dir, int Length, int index_x, int index_y);
};