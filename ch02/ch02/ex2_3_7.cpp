#include <iostream>
#include <vector>

template<typename Continer>
Continer MergeTmp(Continer &lhs, Continer &rhs) {
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
Continer MergeSortTmp(Continer &arr) {
	if (arr.size() > 1) {
		auto mid = arr.begin() + arr.size() / 2;
		auto lhs = MergeSortTmp(Continer(arr.begin(), mid));
		auto rhs = MergeSortTmp(Continer(mid, arr.end()));
		return MergeTmp(lhs, rhs);
	}
	return arr;
}



template <typename Continer>
bool FindIntegerSum(Continer arr, int x) {
	auto sarr = MergeSortTmp(arr); //O(nlgn)
	auto beg = sarr.begin(), end = sarr.end() - 1;
	while (beg != end) {       //O(n)
		if ((*beg + *end) == x)
			return true;
		else if ((*beg + *end) < x)
			beg += 1;
		else if ((*beg + *end) > x)
			end -= 1;
	}
	return false;
}