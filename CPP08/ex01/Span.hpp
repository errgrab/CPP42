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

	void addNumber(unsigned int n);

	unsigned int shortestSpan();
	unsigned int longestSpan();

	class FullException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class NoSpanCanBeFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};
