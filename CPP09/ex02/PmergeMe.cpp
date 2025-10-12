#include "PmergeMe.hpp"

#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <iomanip>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::sortAndPrint(std::vector<int> &vec, std::list<int> &lst) {
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
	std::cout << std::endl;

	clock_t v0 = std::clock();
	PmergeMeSort(vec);
	clock_t v1 = std::clock();
	double tv = double(v1 - v0) * 1e6 / CLOCKS_PER_SEC;

	clock_t l0 = std::clock();
	PmergeMeSort(lst);
	clock_t l1 = std::clock();
	double tl = double(l1 - l0) * 1e6 / CLOCKS_PER_SEC;

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout.setf(std::ios::fixed);
	std::cout << std::fixed << std::setprecision(0);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << tv << " µs" << std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list   : " << tl << " µs" << std::endl;
}