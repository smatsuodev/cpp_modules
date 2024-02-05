#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
	type = wrongAnimal.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "Hmm, what should I say?" << std::endl;
}

const std::string &WrongAnimal::getType() const {
	return type;
}
