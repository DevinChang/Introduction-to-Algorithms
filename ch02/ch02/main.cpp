#include "ex2_1_2.cpp"
#include "ex2_1_3.cpp"
#include "ex2_1_4.cpp"
#include "ex2_2_2.cpp"
#include <vector>


int main() {
	//ex2_1_2
	std::cout << "ex2_1_2: " << std::endl;
	int arr[5] = { 3, 2, 1, 4, 5 };
	InsertSort(arr, 5);
	for (auto p : arr)
		std::cout << p << " ";
	std::cout << std::endl;

	//ex2_1_3
	std::cout << "ex2_1_3: " << std::endl;
	char ctr[5] = { 'a', 'b', 'c', 'd', 'e' };
	auto isfind = FindValue(ctr, 'a', 5);
	if (isfind != NIL)
		std::cout << "value position : " << isfind + 1 << std::endl;
	else
		std::cout << "can not find the value!" << std::endl;

	//ex2_1_4
	std::cout << "ex2_1_4: " << std::endl;
	std::vector<int> v1{ 1, 1, 1 }, v2{ 1, 1, 0 };
	auto iv = AddBinary(v1, v2);
	for (auto &p : iv)
		std::cout << p << " ";
	std::cout << std::endl;

	//ex2_2_2
	std::cout << "ex2_2_2: " << std::endl;
	std::vector<int> ve{ 2, 3, 6, 1, 9, 7 };
	//std::cout << "before sort: " << std::endl;
	for (auto p : ve)
		std::cout << p << " ";
	SelectSort(ve);
	std::cout << std::endl;
	for (auto p : ve)
		std::cout << p << " ";
	std::cout << "\n";

	system("pause");
	return 0;
}