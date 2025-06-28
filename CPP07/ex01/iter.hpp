#pragma once
#include <cstdlib>

template <typename T>
void iter(T *arr, size_t len, void (*f)(T&)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}
