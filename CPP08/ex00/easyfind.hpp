#pragma once
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
	const char *what() const throw() {
		return "Value not found.";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator result;
	result = std::find(container.begin(), container.end(), value);
	if (result == container.end())
		throw ::NotFoundException();
	return result;
}
