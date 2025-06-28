#include <iostream>
#include "Array.hpp"

int main(void) {
	try {
		Array<int> a;
		std::cout << "Default size is: " << a.size() << std::endl;

		Array<int> b(5);
		std::cout << "With size 5 at construction: " << b.size() << std::endl;
		for (size_t i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << std::endl;

		Array<int> c = b;
		c[0] = 100;
		std::cout << "c[0] = " << c[0] << " b[0] = " << b[0] << std::endl;

		Array<int> d;
		d = b;
		d[1] = 200;
		std::cout << "b[1] = " << b[1] << " d[1] = " << d[1] << std::endl;
		
		std::cout << b[10] << std::endl; // SHOULD ERROR HERE
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
