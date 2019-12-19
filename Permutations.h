#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Permutations {
public:

	void SetNumberPool(std::vector<int> InputNumberPool);

	std::vector<int> TotalNumberPool = {};
	std::vector<int> CurrentNumberPool = {};
	std::vector<int> CurrentPermutation = {};
	void FirstLexicographicPermutation();
	void NextLexicographicPermutation();
	void Out();

private:

	void AlphabeticalAfterPoint(int Place);

};