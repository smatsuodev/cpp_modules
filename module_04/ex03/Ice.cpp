#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other.getType()) {}

Ice::~Ice() {
}

Ice &Ice::operator=(const Ice &other) {
	return *this;
}
