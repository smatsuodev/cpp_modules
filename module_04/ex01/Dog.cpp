#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bowwow!" << std::endl;
}
