#pragma once

#include <stdint.h>

struct Data;

class Serializer {
private:
	Serializer();
	Serializer(Serializer &);
	~Serializer();
	Serializer &operator=(Serializer &);

public:
	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);
};

