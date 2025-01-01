#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);
	Point point1(1, 1);
	Point point2(10, 10);

	std::cout << "Point (1, 1) is inside the triangle? " << (bsp(a, b, c, point1) ? "Yes" : "No") << std::endl;
	std::cout << "Point (10, 10) is inside the triangle? " << (bsp(a, b, c, point2) ? "Yes" : "No") << std::endl;
	return 0;
}
