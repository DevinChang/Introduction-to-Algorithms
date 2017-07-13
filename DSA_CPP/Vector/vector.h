#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <initializer_list>
#include <algorithm>
#include <utility>




template <typename> class Vector;
template <typename T>
std::ostream &operator<< (std::ostream &os, const Vector<T> &t);

template <typename T> class Vector {
	friend std::ostream& operator<< <T>(std::ostream &os, const Vector<T> &t);
public:
	//constructor
	Vector() = default;
	Vector(std::initializer_list<T>);
	//copy constructor
	Vector(const Vector<T> &);
	//move constructor
	Vector(Vector<T> &&) noexcept;
	//assignment operator
	Vector &operator= (const Vector<T> &);
	Vector &operator= (std::initializer_list<T>);
	Vector &operator= (Vector<T> &&) noexcept;
	//subscript operator
	T &operator[] (size_t n);
	const T &operator[] (std::size_t n) const;
	//destructor
	~Vector();
public:
	//interface
	void push_back(const T&);
	T &pop() const { return *--first_free; }
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T *begin() { return elements; }
	T *end() { return first_free; }
	template <typename...Args>
	void emplace_back(Args&&...args);
	void resize(size_t n);
	void resize(size_t n, T &);
	void reserve(size_t);
private:
	static std::allocator<T> alloc;
	void check_n_copy() { if (size() == capacity()) reallocate(); }
	std::pair<T *, T *> alloc_n_copy(const T *, const T *);
	void reallocate();
	void reallocate(size_t);
	void free();
	T *elements;
	T *first_free;
	T *cap;
};

template <typename T>
std::allocator<T> Vector<T>::alloc;


