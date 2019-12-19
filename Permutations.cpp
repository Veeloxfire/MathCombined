#include "Permutations.h"

void Permutations::SetNumberPool(std::vector<int> InputNumberPool) {
	TotalNumberPool = InputNumberPool;
}

void Permutations::NextLexicographicPermutation() {
	CurrentNumberPool = {};
	int holder = 0;
	int position = 0;
	holder = CurrentPermutation[CurrentPermutation.size() - 1];
	for (int i = 1; i < (int)CurrentPermutation.size(); i++) {
		if (CurrentPermutation[CurrentPermutation.size() - 1 - i] < holder) {
			position = CurrentPermutation.size() - 1 - i;
			break;
		}
		else {
			CurrentNumberPool.push_back(CurrentPermutation[CurrentPermutation.size() - 1 - i]);
		}
		holder = CurrentPermutation[CurrentPermutation.size() - 1];
	}
	holder = CurrentPermutation[position];
	int nexthighest = 0;
	int nexthighestpos = 0;
	for (int i = 0; i < (int)CurrentNumberPool.size(); i++) {
		if (CurrentNumberPool[i] > nexthighest && CurrentNumberPool[i] > holder) {
			nexthighest = CurrentNumberPool[i];
			nexthighestpos = i;
		}
	}
	
	CurrentPermutation[position] = nexthighest;
	CurrentNumberPool[nexthighestpos] = holder;
	   
	


	AlphabeticalAfterPoint(position);

	CurrentNumberPool = {};
}

void Permutations::AlphabeticalAfterPoint(int point) {
	std::sort(CurrentNumberPool.begin(), CurrentNumberPool.end());
	for (int i = 0; i < (int) CurrentNumberPool.size(); i++) {
		CurrentPermutation[i + point] = CurrentNumberPool[i];
	}
}

void Permutations::Out() {
	for (int i = 0; i < (int) CurrentPermutation.size(); i++) {
		std::cout << CurrentPermutation[i] << " ";
	}
	std::cout << std::endl;
}

void Permutations::FirstLexicographicPermutation() {
	std::sort(TotalNumberPool.begin(), TotalNumberPool.end());
	CurrentPermutation = TotalNumberPool;
}