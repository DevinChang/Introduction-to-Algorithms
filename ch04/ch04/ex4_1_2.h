#include <iostream>




//O(n*n)
template <typename Continer>
Continer FindMaxSubArrBruteForce(Continer arr) {
	auto reit1 = arr.cbegin(), reit2 = arr.cend();
	auto max = *(arr.cbegin());
	for (auto it1 = arr.cbegin(); it1 != arr.cend(); ++it1) {
		
		int sum = 0;
		for (auto it2 = it1; it2 != arr.cend(); ++it2) {
			sum += *it2;
			if (sum > max) {
				max = sum;
				reit1 = it1;
				reit2 = it2;
			}
		}
	}
	return Continer(reit1, reit2 + 1);
}