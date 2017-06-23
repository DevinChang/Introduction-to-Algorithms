#include "ex7_1_1.cpp"
#include <vector>



int main() {
	//ex7_1_1:
	std::cout << "ex7_1_1: " << std::endl;
	std::vector<int> v1{ 3, 1, 7, 8, 2, 5, 4 };
	std::vector<int> v2(5, 1);
	//QuickSort(v1.begin(), v1.end());
	QuickSort(v2.begin(), v2.end());
	for (auto p : v1)
		std::cout << p << " ";
	

	system("pause");
	return 0;
}





