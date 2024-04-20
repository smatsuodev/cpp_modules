#include "Cat.hpp"
#include <iostream>

Cat::Cat() : type("Cat"), brain(new Brain) {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : type(other.type), brain(new Brain) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

const std::string &Cat::getType() const {
	return type;
}
