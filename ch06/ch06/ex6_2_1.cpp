
#include "ex6.h"




//template<typename It>
//It Left(It i) {
//	return i + 2;
//}


template<typename Continer>
void MaxHeapIFY(Continer arr, int i) {
	int l = Left(i), r = Right(i);
	int largest;
	if (l <= arr.size() && arr[l] > arr[i])
		largest = l;
	else
		largest = i;
	if (r <= arr.size() && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		MaxHeapIFY(arr, largest);
	}
}