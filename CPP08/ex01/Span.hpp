#pragma once

#include <vector>

class Span {
private:
	unsigned int N;
	std::vector<int> array;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);

	void addNumber(unsigned int);

	unsigned int shortestSpan();
	unsigned int longestSpan();
};
