#pragma once
#include <vector>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define MINI  -9999



//top-down recursive
int cut_rod(std::vector<int> p, int n) {
	if (n == 0)
		return 0;
	int q = MINI;
	for (int i = 0; i < n; ++i)
		q = max(q, p[i] + cut_rod(p, n - i - 1));
	return q;
}


