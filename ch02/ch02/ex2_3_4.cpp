#include <iostream>



template <typename Continer>
Continer &InsertSortRecursion(Continer &arr, int n) {
	if (n <= 1)
		return arr;
	else {
		InsertSortRecursion(arr, n - 1);
		int i = n - 1, j = i - 1;
		auto key = arr[i];
		for (; j >= 0 && arr[j] > key; --j)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
		return arr;
	}
}