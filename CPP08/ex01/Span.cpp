#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : N(0), array() {}
Span::Span(unsigned int N) : N(N), array() { array.reserve(N); }
Span::Span(const Span &other) : N(other.N), array(other.array) {}
Span::~Span() {}
Span &Span::operator=(const Span &other) {
	if (this != &other) {
		N = other.N;
		array = other.array;
	}
	return *this;
}

void Span::addNumber(unsigned int n) {
	if (array.size() >= N)
		throw Span::FullException();
	array.push_back(n);
}

unsigned int Span::shortestSpan() {
	if (array.size() < 2)
		throw Span::NoSpanCanBeFoundException();
	std::vector<int> array_sorted = array;
	std::sort(array_sorted.begin(), array_sorted.end());
	int min = array_sorted[1] - array_sorted[0];
	for (unsigned long i = 2; i < array_sorted.size(); i++) {
		if ((array_sorted[i] - array_sorted[i - 1]) < min)
			min = (array_sorted[i] - array_sorted[i - 1]);
	}
	return min;
}

unsigned int Span::longestSpan() {
	if (array.size() < 2)
		throw Span::NoSpanCanBeFoundException();
	int min = *std::min_element(array.begin(), array.end());
	int max = *std::max_element(array.begin(), array.end());
	return max - min;
}

const char *Span::CannotAddException::what() const throw() {
	return "range is bigger than the lenght of the array.";
}

const char *Span::FullException::what() const throw() {
	return "the array is full.";
}

const char *Span::NoSpanCanBeFoundException::what() const throw() {
	return "no span can be found.";
}
