#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
	type = cat.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
