#pragma once

#include <exception>
#include <cstdlib>

template <typename T>
class Array {
private:
	T *arr;
	size_t len;
public:
	Array() : arr(NULL), len(0) {}
	Array(unsigned int n) : arr(new T[n]()), len(n) {}
	Array(const Array &other) : arr(new T[other.len]), len(other.len) {
		for (size_t i = 0; i < len; i++)
			arr[i] = other.arr[i];
	}
	Array &operator=(const Array &other) {
		if (this == &other)
			return *this;
		delete[] arr;

		len = other.len;
		arr = new T[len];
		for (size_t i = 0; i < len; i++)
			arr[i] = other.arr[i];
		return *this;
	}
	~Array() {
		delete[] arr;
	}
	T &operator[](size_t index) {
		if (index > len)
			throw std::out_of_range("Index out of bounds");
		return arr[index];
	}
	const T &operator[](size_t index) const {
		if (index > len)
			throw std::out_of_range("Index out of bounds");
		return arr[index];
	}
	size_t size() const {
		return len;
	}
};

