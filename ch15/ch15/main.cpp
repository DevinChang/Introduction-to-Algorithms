#include <iostream>
#include "cut_rod.h"
/************************************************
               Dynamic Programming
************************************************/




int main() {
	std::vector<int> vec{ 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	printf("the best price: %d\n", cut_rod(vec, 4));
	system("pause");
	return 0;
}