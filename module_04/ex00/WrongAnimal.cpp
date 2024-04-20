#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type) {}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "Hmm, what should I say?" << std::endl;
}

const std::string &WrongAnimal::getType() const {
	return type;
}
