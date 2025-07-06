#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	std::srand(std::time(0));
	int random = std::rand() % 3;
	switch (random) {
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return NULL;
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Class A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Class B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Class C" << std::endl;
	} else {
		std::cout << "Impossible!" << std::endl;
	}
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
		return;
	} catch(...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Class B" << std::endl;
		return;
	} catch(...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Class C" << std::endl;
		return;
	} catch(...) {}
	std::cout << "Impossible!" << std::endl;
}

int main(void) {
	Base *randomClass = generate();
	if (!randomClass) {
		std::cout << "Failed to generate random class" << std::endl;
		return 1;
	}
	identify(randomClass);
	identify(*randomClass);
	delete randomClass;
	return 0;
}
