#include "ex6.h"




template<typename Continer>
void MaxHeapNoRecur(Continer arr) {
	int i = 1;
	int l = Left(i), r = Right(i);
	while (i < arr.size() / 2) {
		int largest;
		if (l <= arr.size() && arr[l] > arr[i])
			largest = l;
		else
			largest = i;
		if (r <= arr.size() && arr[r] > arr[largest])
			largest = r;
		if (largest != i) {
			std::swap(arr[i], arr[largest]);
			i = largest;
		}
		else
			break;
	}
}