#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void) {
	std::vector<int> intV;
	intV.push_back(1);
	intV.push_back(2);
	intV.push_back(4);
	std::vector<int>::iterator found;
	for (int i = 0; i < 5; i++) {
		try {
			found = easyfind(intV, i);
			std::cout << "Found: " << i << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << " Number: " << i << std::endl;
		}
	}
	return 0;
}
