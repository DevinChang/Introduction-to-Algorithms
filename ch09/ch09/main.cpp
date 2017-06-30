#include <iostream>
#include <vector>
#include "randomized_select.h"



int main() {
	std::vector<int> v1{ 5, 3, 8, 2, 1, 6 };
	int i = 1;
	int key = RandomizedSelect(v1, i);
	std::cout << "第" << i << "小的元素是: " << key << std::endl;
	system("pause");
	return 0;
}