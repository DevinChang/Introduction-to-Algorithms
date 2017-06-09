#include "ex4_1_2.h"
#include "ex4_1_3.cpp"
#include <vector>


int main() {
	//ex4_1_2
	std::cout << "ex4_1_2: " << std::endl;
	std::vector<int> vec{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	auto retvec = FindMaxSubArrBruteForce(vec);
	for (auto p : retvec)
		std::cout << p << " ";
	std::cout << std::endl;

	//ex4_1_3
	std::cout << "ex4_1_3: " << std::endl;
	auto retu = FindMaxSubArr(vec);
	auto tmpve = std::get<0>(retu);
	for (auto p : tmpve)
		std::cout << p << " ";
	//std::cout << "the max arr result: " << std::get<1>(retu) << std::endl;
	std::cout << "\n";
	system("pause");
	return 0;
}