#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

struct Data {
	std::string name;
	int rating;
	bool virgin;
};

void printData(Data* data) {
	std::cout << "=== info ===" << std::endl;
	std::cout << "Nome: " << data->name << std::endl;
	std::cout << "Nota: " << data->rating << " de 10" << std::endl;
	std::cout << (data->virgin ? "É virgem" : "Não sabe nada sobre signo") << std::endl;
	std::cout << "=== end info ===" << std::endl;
}

void doTest(Data *info) {
	uintptr_t info_serialized = Serializer::serialize(info);
	std::cout << "=== test ===" << std::endl;
	std::cout << "Original: " << info << std::endl;
	std::cout << "Serialized: " << info_serialized << std::endl;
	std::cout << "Deserialized: " << Serializer::deserialize(info_serialized) << std::endl;
	std::cout << "=== end test ===" << std::endl;
}


int main(void) {
	Data *info = new Data;

	info->name = "Lucas";
	info->rating = 7; // out of 10
	info->virgin = true;

	printData(info);

	doTest(info);

	delete info;
	return 0;
}
