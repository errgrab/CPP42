#include <iostream>
#include "Converter.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <value>" << std::endl;
		return 1;
	}
	Converter::show(av[1]);
	return 0;
}
