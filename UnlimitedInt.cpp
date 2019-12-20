#include "UnlimitedInt.h"


void UnlimitedInt::AddInt(int input) {
	AddIntAtPoint(input, 0);
}

void UnlimitedInt::AddIntAtPoint(int input, int point) {
	if ((int)Number.size() - 1 < point) {
		Number.push_back(0);
	}
	if (Number[point] + input >= 0 && Number[point] + input < perdigit) {
		Number[point] += input;
	}
	else {
		int add = Number[point] + input;
		int nextdigit = howmanydigits(add);
		if (Number.size() -1 <= point) {
			Number.push_back(nextdigit);
		}
		else {
			Number[point+1] += nextdigit;
		}

		Number[point] += input - (perdigit * nextdigit);
	}
}

void UnlimitedInt::MultiplyByInt(int input) {
	if (input == 0) {
		std::vector<int> zero;
		zero.push_back(0);
		Number = zero;
		return;
	}
	if (input == 1) {
		return;
	}
	UnlimitedInt holder;
	holder.Number = Number;
	for (int i = 0; i < input-1; i++) {
		AddUnlimitedInt(holder);
	}
}

int UnlimitedInt::howmanydigits(int input) {

	for (int i = 1; i < 10; i++) {
		input -= perdigit;
		if (input >= 0 && input < perdigit) {
			return i;
		}
	}
	return 0;
}

void UnlimitedInt::AddUnlimitedInt(UnlimitedInt& input) {
	input.cleanup();
	cleanup();
	vector<int> SmallInt = input.Number.size() < Number.size() ? input.Number : Number;
	vector<int> BigInt = input.Number.size() >= Number.size() ? input.Number : Number;

	Number = BigInt;


	for (unsigned i = 0; i < SmallInt.size(); i++) {
		AddIntAtPoint(SmallInt[i], i);
	}
}

std::string UnlimitedInt::asString() {

	cleanup();

	std::string output = "";
	for (int i = 0; i < Number.size(); i++ ){
		output = digitAsString(i) + output;
	}
	return output;
}

std::string UnlimitedInt::digitAsString(int point) {
	std::string str1 = std::to_string(Number[point]);
	if (point < Number.size() - 1) {
		while (str1.length() < 9) {
			str1 = "0" + str1;
		}
	}
	return str1;
}

int UnlimitedInt::numDigits() {
	cleanup();

	return floor(log10(Number[Number.size() - 1])) + ((Number.size()-1)*ceil(log10(perdigit))) + 1;
}

void UnlimitedInt::cleanup() {
	while (Number[Number.size() - 1] == 0 && Number.size()>1) {
		Number.pop_back();
	}
}

void UnlimitedInt::stringToUnlimited(std::string &input) {
	int holder;
	int length = input.length();
	int unitlength = std::ceil(std::log10(perdigit));
	for (int i = 0; (unitlength*i) < length; i++) {
		
		if (length - (9 * (i + 1)) > 0) {		
			holder = std::stoi(input.substr(length - (unitlength * (i + 1)), unitlength));
			AddIntAtPoint(holder,i);
		}
		else {
			
			holder = std::stoi(input.substr(0, length - (unitlength * i)));
			AddIntAtPoint(holder, i);
		}
	}
}

int UnlimitedInt::addDigitsAtPoint(int point) {
	std::string num = to_string(Number[point]);
	int output = 0;

	for (int i = 0; i < num.size(); i++) {
		output += stoi(num.substr(i, 1));
	}

	return output;
}

int UnlimitedInt::sumDigits() {
	int output = 0;

	for (int i = 0; i < Number.size(); i++) {
		output += addDigitsAtPoint(i);
	}
	
	return output;
}

