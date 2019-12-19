#include "Factors.h"
#include <iostream>
Factors::Factors(PrimeList* PrimesAddress) {
	Primes = PrimesAddress;
}

void Factors::FindPrimeFactors(int input) {
	int num = input;
	FactorsOfInput = {};

	if (Primes->PrimeCheck(num)) {
		FactorsOfInput = { input };
		return;
	}

	while (num > 1) {
		for (int i = 0; i < (int) Primes->List.size(); i++) {
			if (num % Primes->List[i] == 0) {
				FactorsOfInput.push_back(Primes->List[i]);
				num = num / Primes->List[i];
				break;
			}
		}
	}
}

void Factors::FindProperDivisors(int input) {
	FactorsOfInput = {};
	for (int i = 1; i < input; i++) {
		if (input % i == 0) {
			FactorsOfInput.push_back(i);
		}
	}
}

void Factors::FindAllDivisors(int input) {
	FactorsOfInput = {};
	FindProperDivisors(input);
	FactorsOfInput.push_back(input);
}

int Factors::SumCurrentDivisors() {
	int sum = 0;
	for (int i = 0; i < FactorsOfInput.size(); i++) {
		sum += FactorsOfInput[i];
	}
	return sum;
}