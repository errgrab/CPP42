#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer() {}
Serializer::Serializer(Serializer &) {}
Serializer::~Serializer() {}
Serializer &Serializer::operator=(Serializer &) {return *this;}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
};

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
};
