// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "UnlimitedInt.h"
#include "Fibonacci.h"
#include "StringManip.h"
#include "Grid.h"
#include <iostream>


int main()
{


	
	



	UnlimitedInt test;

	std::string test2 = "1";
	
	test.stringToUnlimited(test2);

	for (int i = 1; i <= 100; i++) {
		if(i%10==1){ std::cout << i-1 << "! = " << test.asString() << "\n"; }
		test.MultiplyByInt(i);
	}


	std::cout << test.asString() << "\n";
	std::cout << test.sumDigits() << " ";
	
	

	

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
