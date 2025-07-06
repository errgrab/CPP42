#include "Span.hpp"
#include <iostream>

Span::Span() : N(0), array() {}
Span::Span(unsigned int N) : N(N), array() { array.reserve(N); }
Span::Span(const Span &other) : N(other.N), array(other.array) {}
Span &operator=(const Span &other) {
	if (other == *this) {
		return *this;
	}
	return *this;
}


