#include "Factors.h"
class AbundantNumbers {
public:
	AbundantNumbers(Factors* FactorsAddress);

	std::vector<int> List = { 12 };
	void ExtendList(int Limit);

private:
	Factors* Factor;
};