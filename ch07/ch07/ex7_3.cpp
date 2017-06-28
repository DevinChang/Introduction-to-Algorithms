#include <iostream>
#include <random>


template<typename It>
It Partition(It beg, It end) {
	It pivot = end - 1;
	//int key = *pivot;
	auto first = beg;
	for (auto it = beg; it != end - 1; ++it) {
		if (*it <= *pivot) {
			std::swap(*first, *it);
			++first;
		}
	}
	//bug fixed: 2017/6/23 
	//原先swap(*first, key)，这样会造成迭代器不会前置寻址时出错。这是因为，如果写成这样，交换的仅仅是first指向的值，
	//pivot指向的值并没有改变。
	std::swap(*first, *pivot);
	return first;
}

template<typename It>
It RandomPartition(It beg, It end) {
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u(0, 9);
	auto range = end - beg;
	It pivot = beg + u(e) * range / 10;
	std::swap(*pivot, *(end - 1));
	return Partition(beg, end);
}


template<typename It>
void RandomQuickSort(It beg, It end) {
	if (end - beg > 1) {
		auto pivot = RandomPartition(beg, end);
		RandomQuickSort(beg, pivot);
		RandomQuickSort(pivot + 1, end);
	}
}