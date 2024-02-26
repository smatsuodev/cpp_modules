#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	if (this == &dog) {
		return *this;
	}

	type = dog.type;
	delete brain;
	brain = new Brain(*dog.brain);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bowwow!" << std::endl;
}
