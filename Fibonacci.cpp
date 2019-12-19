#include "Fibonacci.h"

void fibonacci::nextFibInt() {
	intIndex++;
	int F1_holder = F2_int;
	F2_int += F1_int;
	F1_int = F1_holder;
}

void fibonacci::nextFibUnlimited() {
	UnlimitedIndex++;
	UnlimitedInt F1_holder = F2_unlimited;
	F2_unlimited.AddUnlimitedInt(F1_unlimited);
	F1_unlimited = F1_holder;
}

void fibonacci::setStart(int f1, int f2) {
	F1_int = f1;
	F2_int = f2;
}

void fibonacci::setStart(UnlimitedInt& f1, UnlimitedInt& f2) {
	F1_unlimited = f1;
	F2_unlimited = f2;
}