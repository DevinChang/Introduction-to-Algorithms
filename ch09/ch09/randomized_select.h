#include "random_partition.h"



template<typename Continer>
inline int RandomizedSelect(Continer arr, int i) {
	if (arr.size() == 1)
		return *arr.begin();
	auto pivot = RandomPartition(arr.begin(), arr.end());
	int k = pivot - arr.begin() + 1;
	if (k == i)
		return *pivot;
	else if (i < k)
		return RandomizedSelect(Continer(arr.begin(), pivot), i);
	else
		return RandomizedSelect(Continer(pivot + 1, arr.end()), i - k);
}