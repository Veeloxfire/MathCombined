#include "StringManip.h"


std::vector<std::string> StringManip::LinesToVector(std::string &input) {
	int found = 0;
	int holder = 0;
	std::vector<std::string> output;

	while (found != std::string::npos) {
		found = input.find(" ", found + 1);

		output.push_back(input.substr(holder,found-holder));

		holder = found+1;
	}

	return output;
}