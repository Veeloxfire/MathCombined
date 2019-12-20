#pragma once

#include <vector>
#include <string>


class StringManip {
public:
	std::vector<std::string> SplitToVector(std::string &input);

	std::vector<std::string> SplitToVector(std::string& input, int start_index, int end_index);
};