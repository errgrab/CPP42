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
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	clock_t startVec = clock();
	PmergeMeSort(vec);
	clock_t endVec = clock();
	double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

	clock_t startList = clock();
	PmergeMeSort(lst);
	clock_t endList = clock();
	double timeList = (double(endList - startList) / CLOCKS_PER_SEC) * 1e6;

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list   : " << timeList << " us" << std::endl;
}