#include <iostream>



template <typename Continer>
Continer AddBinary(Continer const &lhs, Continer const &rhs) {
	int len = lhs.size() + 1;
	Continer sum(len);
	unsigned carry = 0, bit_sum = 0;
	for (auto it1 = lhs.crbegin(), it2 = rhs.crbegin(); it1 != lhs.crend(), it2 != rhs.crend(); ++it1, ++it2) {
		bit_sum = (*it1 + *it2 + carry) % 2;
		carry = (*it1 + *it2) / 2;
		//sum.push_back(bit_sum);
		sum[--len] = bit_sum;
	}
	auto it1 = lhs.cbegin(), it2 = rhs.cbegin();
	if (*it1 + *it2 > 1)
		sum[0] = 1;
	return sum;
}