#pragma once
#include "PrimeList.h"

class Factors {

public:
	Factors(PrimeList* PrimesAddress);
	void FindPrimeFactors(int input);
	void FindAllDivisors(int input);
	void FindProperDivisors(int input);

	int SumCurrentDivisors();

	std::vector<int> FactorsOfInput = {};


private:
	PrimeList* Primes;
};
