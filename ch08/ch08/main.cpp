#include "counting_sort.h"
#include <vector>



int main() {
	std::vector<int> v1{ 2, 5, 3, 0, 2, 3, 0, 3 };
	auto result = CountingSort(v1, 5);
	for (auto p : result)
		std::cout << p << " ";


	system("pause");
	return 0;
}