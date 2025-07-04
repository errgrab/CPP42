#pragma once

template <typename T>
class Span {
private:
	unsigned int N;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);

};
