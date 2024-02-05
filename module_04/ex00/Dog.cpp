#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
	type = dog.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bowwow!" << std::endl;
}
