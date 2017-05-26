#include <iostream>



template<typename Continer>
void SelectSort(Continer &arr) {
	int len = arr.size();
	for (int i = 0; i < len - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < len; ++j) {
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i) {
			auto tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}	
	}
}