#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Hmm, what should I say?" << std::endl;
}

const std::string &Animal::getType() const {
	return type;
}
