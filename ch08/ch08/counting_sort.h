#include <iostream>



template<typename Continer>
inline Continer CountingSort(Continer A, int k) {
	Continer C(k + 1, 0), B(A.size(), 0);
	for (int i = 0; i < A.size(); ++i)
		C[A[i]]++;
	for (int i = 1; i <= k; ++i)
		C[i] = C[i - 1] + C[i];
	for (int j = A.size() - 1; j > 0; --j) {
		//数组是从0开始。故要将数组C对应元素作为B的下标来存放数据，则要减一。
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
	return Continer(B.begin() + 1, B.end());
}




