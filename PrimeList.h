#pragma once
#include <vector>

class PrimeList {
public:
	std::vector<int> List = { 2 };

	bool PrimeCheck(int num);

private:
	void ExtendList(int Limit);
};