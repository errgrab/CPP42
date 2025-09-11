#include "PmergeMe.hpp"

#include <iostream>
#include <limits>
#include <vector>
#include <list>
#include <cstdlib>
#include <climits>

int main(int argc, char **argv) {
	PmergeMe pmerge;
	if (argc < 2) {
		std::cerr << "Error: No input." << std::endl;
		return 1;
	}
	std::vector<int> vec;
	std::list<int> lst;
	for (int i = 1; i < argc; i++) {
		char *endptr;
		long num = std::strtol(argv[i], &endptr, 10);
		
		if (*endptr != '\0') {
			std::cerr << "Error: Invalid number '" << argv[i] << "'." << std::endl;
			return 1;
		}
		if (num < 0) {
			std::cerr << "Error: Negative numbers are not allowed." << std::endl;
			return 1;
		}
		if (num > INT_MAX) {
			std::cerr << "Error: Number out of range '" << argv[i] << "'." << std::endl;
			return 1;
		}
		vec.push_back(static_cast<int>(num));
		lst.push_back(static_cast<int>(num));
	}
	pmerge.sortAndPrint(vec, lst);
	return 0;
}