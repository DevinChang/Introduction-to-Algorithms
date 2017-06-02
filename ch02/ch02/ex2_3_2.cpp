#include <iostream>
#include <vector>

template<typename Continer>
Continer Merge(Continer &lhs, Continer &rhs) {
	Continer ret;
	auto it1 = lhs.cbegin(), it2 = rhs.cbegin();
	while (it1 != lhs.cend() && it2 != rhs.cend())
		ret.push_back((*it1 < *it2) ? *it1++ : *it2++);
	while (it1 != lhs.cend())
		ret.push_back(*it1++);
	while (it2 != rhs.cend())
		ret.push_back(*it2++);
	return ret;
}

template <typename Continer>
Continer MergeSort(Continer &arr) {
	if (arr.size() > 1) {
		auto mid = arr.begin() + arr.size() / 2;
		auto lhs = MergeSort(Continer(arr.begin(), mid));
		auto rhs = MergeSort(Continer(mid, arr.end()));
		return Merge(lhs, rhs);
	}
	return arr;
}
