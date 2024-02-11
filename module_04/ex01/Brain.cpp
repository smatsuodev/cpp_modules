#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
	if (this == &brain) {
		return *this;
	}

	for (int i = 0; i < NUM_OF_IDEAS; i++) {
		ideas[i] = brain.ideas[i];
	}
	return *this;
}
