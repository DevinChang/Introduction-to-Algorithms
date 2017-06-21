#include "ex6_2_2.cpp"



template<typename Continer>
void BuildMinHeap(Continer arr) {
	int heaplen = arr.size();
	for (int i = heaplen / 2; i > 0; --i)
		MinHeapIFY(arr, i);
}

//template<typename Continer>
//void MergeKList(Continer l1, Continer l2, Continer l3, Continer l4) {
//	int tmparr[4];
//	auto l1it = l1.begin(), l2it = l2.begin(), l3it = l3.begin(), l4it = l4.begin();
//	while (l1it != l1.end() && l2it != l2.end() && l3it != l3.end() && l4it != l4.end()) {
//		
//
//	}
//}


