#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
	if (this == &cat) {
		return *this;
	}

	type = cat.type;
	delete brain;
	brain = new Brain(*cat.brain);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
