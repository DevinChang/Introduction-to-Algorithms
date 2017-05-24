#include <iostream>

#define NIL -1


//notice: 此处需定义两个模板参数，是因为，第一个参数要传入的是个数组，而第二个需要传入
//的则为该数组中某个值。
template<typename T, typename N>
int FindValue(T arr, N v, int len) {
	for (int i = 0; i < len; ++i) {
		if (arr[i] == v)
			return i;
	}
	return NIL;
}