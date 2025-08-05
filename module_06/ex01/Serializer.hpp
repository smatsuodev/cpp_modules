#ifndef CPP_MODULES_SERIALIZER_HPP
#define CPP_MODULES_SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();
	Serializer &operator=(const Serializer &other);
};

#endif
