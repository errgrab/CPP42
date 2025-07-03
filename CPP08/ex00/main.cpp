#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

void testVector(void) {
	std::cout << "=== Vector ===" << std::endl;
	std::vector<int> intV;
	intV.push_back(1);
	intV.push_back(2);
	intV.push_back(4);
	std::vector<int>::iterator found;
	std::cout << "It should find 1, 2 and 4." << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cout << "Trying " << i << ": ";
		try {
			found = easyfind(intV, i);
			std::cout << "Value found." << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void testList(void) {
	std::cout << "=== List ===" << std::endl;
	std::list<int> intL;
	intL.push_back(0);
	intL.push_back(3);
	intL.push_back(5);
	std::list<int>::iterator found;
	std::cout << "It should find 0, 3 and 5." << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cout << "Trying " << i << ": ";
		try {
			found = easyfind(intL, i);
			std::cout << "Value found." << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

int main(void) {
	testVector();
	testList();
	return 0;
}
