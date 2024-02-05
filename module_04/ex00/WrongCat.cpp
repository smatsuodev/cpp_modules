#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = wrongCat;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
	type = wrongCat.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
