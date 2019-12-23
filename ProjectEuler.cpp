// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Matrix.h"
#include <iostream>


int func(int x, std::vector<int>& poly) {
	int output = 0;
	for (int i = 0; i < poly.size(); i++) {
		output += poly[i] * pow(x, i);
	}
	return output;
}

float func(int x, std::vector<float>& poly) {
	int output = 0;
	for (int i = 0; i < poly.size(); i++) {
		output += poly[i] * pow(x, poly.size() - 1 - i);
	}
	return output;
}

int main()
{
	Matrix test(1, 1);
	Matrix inputs(1, 1);
	Matrix results(1, 1);

	std::vector<int> polynomial_final;

	for (int i = 0; i < 11; i++) {
		polynomial_final.push_back(pow(-1, i));
		std::cout << polynomial_final[i];
	}

	std::cout << std::endl;

	std::vector<float> holder_polynomial;

	float output = 0;

	for (int i = 0; i < polynomial_final.size(); i++) {
		test.resize(i + 1, i + 1);
		inputs.resize(1, i + 1);
		results.resize(1, i + 1);
		
		for (int j = 1; j <= i + 1; j++) {
			for (int k = 1; k <= i + 1; k++) {
				test.set(k, j, pow(j, (i + 1 - k)));
			}
			results.set(1, j, func(j, polynomial_final));
		}

		test.print();
		
		inputs = (test.inverse()) * results;

		inputs.print();

		holder_polynomial = inputs.column_to_vector(1);


		for (int j = 0; j < holder_polynomial.size(); j++) {
			std::cout << func(j+1, holder_polynomial) << " ";
		}
		std::cout << std::endl;
		for (int j = 0; j < polynomial_final.size(); j++) {
			std::cout << func(j + 1, polynomial_final) << " ";
		}
		std::cout << std::endl;
		
		output += func(i + 1, holder_polynomial);
	}
	
	std::cout << output << std::endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
