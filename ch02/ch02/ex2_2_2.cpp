#include <iostream>



//notice: 注意外循环的i的范围是[0, len-1),因为若当i的上界为len时，最后一层循环的i可以取len-1, 内层循环的j则为len.
//因j不小于len，故不会进入到内层循环。所以i的范围为[0,len-1)时就已经足够遍历完整个数组中的元素。
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