#pragma once
#include "UnlimitedInt.h"

class fibonacci {
public:
	UnlimitedInt F1_unlimited, F2_unlimited;
	int F1_int, F2_int;
	void nextFibInt();
	void nextFibUnlimited();

	int intIndex = 2;
	int UnlimitedIndex = 2;

	void setStart(int f1, int f2);
	void setStart(UnlimitedInt& f1, UnlimitedInt& f2);
};