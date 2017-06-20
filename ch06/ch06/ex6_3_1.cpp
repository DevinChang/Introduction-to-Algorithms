#include "ex6_2_1.cpp"



template<typename Continer>
void BuildMaxHeap(Continer arr) {
	int heaplen = arr.size();
	for (int i = heaplen / 2; i > 0; --i)
		MaxHeapIFY(arr);
}




