#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < NUM_OF_IDEAS; i++) {
		ideas[i] = other.ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < NUM_OF_IDEAS; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
