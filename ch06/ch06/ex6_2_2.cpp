
#include "ex6.h"




template<typename Continer>
void MinHeapIFY(Continer arr, int i) {
	int l = Left(i), r = Right(i);
	int min;
	if (l <= arr.size() && arr[l] < arr[i])
		min = l;
	else
		min = i;
	if (r <= arr.size() && arr[r] < arr[min])
		min = r;
	if (min != i) {
		std::swap(arr[i], arr[min]);
		MinHeapIFY(arr, min);
	}
}