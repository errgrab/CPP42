#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	MutantStack &operator=(const MutantStack &other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	void push_back(const T &t) { this->push(t); }
	void pop_back() { this->pop(); }

	T &back() { return this->top(); }
	const T &back() const { return this->top(); }
};
