#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include "Brain.hpp"

class Animal {
public:
	virtual ~Animal();
	virtual void makeSound() const = 0;
	virtual const std::string &getType() const = 0;
};

#endif
