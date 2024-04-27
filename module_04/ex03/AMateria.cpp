#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : type(type) {}

std::string const &AMateria::getType() const {
	return type;
}

AMateria::AMateria(const AMateria &other) : type(other.type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

void AMateria::use(ICharacter &target) {
	(void) target;
}
