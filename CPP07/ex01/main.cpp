#include "iter.hpp"
#include <iostream>
#include <cmath>

template <typename T>
void printVal(T &val) {
	std::cout << val << " ";
}

void sumPrev(int &val) {
	static int prev;
	val = val + prev;
	prev = val;
}

void testInt(void) {
	std::cout << "=== INT ===" << std::endl;

	int arr[] = {1, 3, 6, 7, 9, 20, 35 };
	size_t len = sizeof(arr) / sizeof(int);

	std::cout << "Values: ";
	iter(arr, len, printVal);
	std::cout << std::endl;

	iter(arr, len, sumPrev);

	std::cout << "Values: ";
	iter(arr, len, printVal);
	std::cout << std::endl;
}

void toUpper(std::string &val) {
	for (size_t i = 0; i < val.length(); i++)
		val[i] = std::toupper(val[i]);
}

void testString(void) {
	std::cout << "=== STR ===" << std::endl;

	std::string arr[] = { "Era", "uma", "vEz", "?" };
	size_t len = sizeof(arr) / sizeof(std::string);

	std::cout << "Values: ";
	iter(arr, len, printVal);
	std::cout << std::endl;

	iter(arr, len, toUpper);

	std::cout << "Values: ";
	iter(arr, len, printVal);
	std::cout << std::endl;
}

void toFloor(float &val) {
	val = floor(val);
}

void testFloat() {
	std::cout << "=== FLT ===" << std::endl;

	float arr[] = { 1.2, 0.29, 29.3, 20.0009 };
	size_t len = sizeof(arr) / sizeof(float);

	std::cout << "Values: ";
	iter(arr, len, printVal);
	std::cout << std::endl;

	iter(arr, len, toFloor);

	std::cout << "Values: ";
	iter(arr, len, printVal);
	std::cout << std::endl;
}

int main(void) {
	testInt();
	testString();
	testFloat();
}
