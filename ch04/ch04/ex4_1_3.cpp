#include <iostream>
#include <tuple>



template<typename Continer>
std::tuple<Continer, int> FindMaxCrossingSubArr(Continer arr) {
	int leftsum = 0, rightsum = 0;
	auto sum = 0;
	auto mid = arr.begin() + arr.size() / 2;
	auto releft = arr.begin(), reright = arr.end();
	//auto end = arr.rend();
	auto times = mid - arr.begin() + 1;
	auto it = mid;
	
	while (times--) {
		sum += *it;
		if (sum > leftsum) {
			leftsum = sum;
			releft = it;
		}
		if (it != arr.begin())
			it--;
	}
	for (auto it = mid + 1; it != arr.end(); ++it) {
		sum += *it;
		if (sum > rightsum) {
			rightsum = sum;
			//modify 2017/6/9/22:08: 切结，因为若是用c++容器来实现，右数组的右边界，即迭代器一定时指向尾元素的下一个元素。
			reright = it + 1;
		}
	}
	std::tuple<Continer, int> ret(Continer(releft, reright), leftsum + rightsum);
	return ret;
}



template<typename Continer>
std::tuple<Continer, int> FindMaxSubArr(Continer arr) {
	//modify 2017/6/9/22:06: 当边界条件改成<=2时，进入if的语句时arr的大小最大包含了两个元素，这样就可以避免递归求右数组时arr的size为0的问题。
	//若还是原先的<=1,则满足条件时arr中只含有一个元素。虽然在《算法导论》书中的条件时只含有一个元素的边界条件，但是，此时我们
	//需要利用c++的特性，利用容器来实现。所以，为了避免递归时出现arr的size为0的问题，可以用此方法实现。

	//modify 2017/6/9/22:40: 经调试发现，问题其实出在当arr的size为0时，保存在tuple中的元素是解迭代器得到的，所以只要比较arr.begin()是否等于
	//arr.end()，若等于则表示arr的size为0，其中没有元素，可将保存在tuple中的sum置为0.
	if (arr.size() <= 1)
		return std::make_tuple(Continer(arr.begin(), arr.end()), arr.begin() == arr.end() ? 0 : *arr.begin());
	else {
		auto mid = arr.begin() + arr.size() / 2;
		auto left = FindMaxSubArr(Continer(arr.begin(), mid));
		auto right = FindMaxSubArr(Continer(mid + 1, arr.end()));
		auto cross = FindMaxCrossingSubArr(arr);		
		if (std::get<1>(left) >= std::get<1>(right) && std::get<1>(left) >= std::get<1>(cross))
			return left;
		else if (std::get<1>(right) >= std::get<1>(left) && std::get<1>(right) >= std::get<1>(cross))
			return right;
		else
			return cross;
	}
}