#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
