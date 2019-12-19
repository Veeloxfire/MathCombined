#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;
class UnlimitedInt {
public:
	vector<int> Number = { 0 };

	void AddInt(int input);
	void AddUnlimitedInt(UnlimitedInt& input);
	std::string asString();

	void stringToUnlimited(std::string& input);

	int numDigits();
	void cleanup();

private:
	int howmanydigits(int input);
	int perdigit = 1000000000;
	void AddIntAtPoint(int input, int point);
	std::string digitAsString(int point);
};