#include "Animal.hpp"
#include <iostream>

Animal::Animal() : brain(new Brain) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type), brain(new Brain) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
	delete brain;
}

Animal &Animal::operator=(const Animal &animal) {
	if (this == &animal) {
		return *this;
	}

	type = animal.type;
	delete brain;
	brain = new Brain(*animal.brain);
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Hmm, what should I say?" << std::endl;
}

const std::string &Animal::getType() const {
	return type;
}
