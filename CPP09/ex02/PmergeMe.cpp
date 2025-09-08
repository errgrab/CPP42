#include "PmergeMe.hpp"

#include <stdio.h>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _list(other._list) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) _vec = other._vec;
	return *this;
}
PmergeMe::~PmergeMe() {}


