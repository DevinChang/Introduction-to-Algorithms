#pragma once

#include "../Vector/vector.h"

template<typename T>
class Stack {
public:
	void push(T const &t) { return vec.push_back(t); }
	T pop() { return vec.pop(); }
	T &top() { return *(vec.end() - 1); }
private:
	Vector<T> vec;
	
};