#include "AbundantNumbers.h"

AbundantNumbers::AbundantNumbers(Factors* FactorsAddress) {
	Factor = FactorsAddress;
}

void AbundantNumbers::ExtendList(int Limit) {
	bool isAbundant = false;
	int num = List[List.size() - 1];
	while (num < Limit || isAbundant == false) {
		isAbundant = false;
		Factor->FindProperDivisors(num);
		if (Factor->SumCurrentDivisors() > num) {
			isAbundant = true;
			List.push_back(num);
		}
		num++;
	}
}