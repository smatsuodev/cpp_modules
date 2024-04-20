#include "Animal.hpp"
#include <iostream>

Animal::Animal() : brain(new Brain) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : brain(new Brain), type(type) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : brain(new Brain(*other.brain)), type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
	delete brain;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Hmm, what should I say?" << std::endl;
}

const std::string &Animal::getType() const {
	return type;
}
