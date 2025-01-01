#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside1(1, 1);
    Point inside2(3, 2);
    Point inside3(2, 3);
    Point inside4(4, 2);

    Point vertexA(0, 0);
    Point vertexB(10, 0);
    Point vertexC(0, 10);

    Point edgeAB(5, 0);
    Point edgeAC(0, 5);
    Point edgeBC(5, 5);

    Point outside1(10, 10);
    Point outside2(-1, -1);
    Point outside3(11, 5);
    Point outside4(-5, 5);

    Point degenerateA(0, 0);
    Point degenerateB(5, 5);
    Point degenerateC(10, 10);
    Point degenerateInside(2, 2);
    Point degenerateOutside(3, 4);

    std::cout << "=== Points Inside Triangle ===" << std::endl;
    std::cout << "Point (1,1): " << (bsp(a, b, c, inside1) ? "True" : "False") << std::endl;
    std::cout << "Point (3,2): " << (bsp(a, b, c, inside2) ? "True" : "False") << std::endl;
    std::cout << "Point (2,3): " << (bsp(a, b, c, inside3) ? "True" : "False") << std::endl;
    std::cout << "Point (4,2): " << (bsp(a, b, c, inside4) ? "True" : "False") << std::endl;

    std::cout << "\n=== Points On Triangle Vertices ===" << std::endl;
    std::cout << "Point (0,0) (vertex A): " << (bsp(a, b, c, vertexA) ? "True" : "False") << std::endl;
    std::cout << "Point (10,0) (vertex B): " << (bsp(a, b, c, vertexB) ? "True" : "False") << std::endl;
    std::cout << "Point (0,10) (vertex C): " << (bsp(a, b, c, vertexC) ? "True" : "False") << std::endl;

    std::cout << "\n=== Points On Triangle Edges ===" << std::endl;
    std::cout << "Point (5,0) (edge AB): " << (bsp(a, b, c, edgeAB) ? "True" : "False") << std::endl;
    std::cout << "Point (0,5) (edge AC): " << (bsp(a, b, c, edgeAC) ? "True" : "False") << std::endl;
    std::cout << "Point (5,5) (edge BC): " << (bsp(a, b, c, edgeBC) ? "True" : "False") << std::endl;

    std::cout << "\n=== Points Outside Triangle ===" << std::endl;
    std::cout << "Point (10,10): " << (bsp(a, b, c, outside1) ? "True" : "False") << std::endl;
    std::cout << "Point (-1,-1): " << (bsp(a, b, c, outside2) ? "True" : "False") << std::endl;
    std::cout << "Point (11,5): " << (bsp(a, b, c, outside3) ? "True" : "False") << std::endl;
    std::cout << "Point (-5,5): " << (bsp(a, b, c, outside4) ? "True" : "False") << std::endl;

    std::cout << "\n=== Degenerate Triangle ===" << std::endl;
    std::cout << "Point (2,2): " << (bsp(degenerateA, degenerateB, degenerateC, degenerateInside) ? "True" : "False") << std::endl;
    std::cout << "Point (3,4): " << (bsp(degenerateA, degenerateB, degenerateC, degenerateOutside) ? "True" : "False") << std::endl;

    return 0;
}
