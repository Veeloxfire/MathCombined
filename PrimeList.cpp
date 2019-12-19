#include "PrimeList.h"

void PrimeList::ExtendList(int Limit) {
	bool isPrime = true;
	int num = List[List.size()-1];
	while (num < Limit || isPrime == false) {
		isPrime = true;
		for (int i = 0; i < (int) List.size(); i++) {
			if (num % List[i] == 0) {
				isPrime = false;
			}
		}
		if (isPrime == true) {
			List.push_back(num);
		}
		num++;
	}
}

bool PrimeList::PrimeCheck(int num) {
	if (num > List[List.size() - 1]) {
		ExtendList(num+1);
	}
	for (int i = 0; i < (int) List.size(); i++) {
		if (List[i] == num) {
			return true;
		}
	}
	return false;
}