#include "ex7_1_1.cpp"
#include "ex7_3.cpp"
#include <vector>



//int random(std::vector<int> v1) {
//	static std::default_random_engine e;
//	static std::uniform_int_distribution<unsigned> u(0, 9);
//	auto range = v1.end() - v1.begin();
//	
//	return  u(e) * range / 10;
//}


int main() {
	//ex7_1_1:
	std::cout << "ex7_1_1: " << std::endl;
	std::vector<int> v1{ 3, 1, 7, 8, 2, 5, 4 };
	//QuickSort(v1.begin(), v1.end());
	QuickSort(v1.begin(), v1.end());
	for (auto p : v1)
		std::cout << p << " ";
	std::cout << std::endl;

	//ex7_3:
	std::cout << "random quicksort: " << std::endl;
	std::vector<int> v2{ 2, 7, 9, 1, 6, 3, 4, 10, 5 };
	RandomQuickSort(v2.begin(), v2.end());
	for (auto p : v2)
		std::cout << p << " ";
	

	system("pause");
	return 0;
}





