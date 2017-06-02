#include <iostream>




template <typename Continer, typename T>
bool BinarySearch(Continer &arr, T key) {
	auto mid = arr.begin() + arr.size() / 2;
	auto beg = arr.begin(), end = arr.end();
	while (beg != end) {
		if (key < *mid) {
			end = mid;
			mid = beg + (mid - beg) / 2;
		}
		else if (key == *mid)
			return true;
		else {
			beg = mid + 1;
			mid = mid + (end - mid) / 2;
		}
	}
	return false;
}