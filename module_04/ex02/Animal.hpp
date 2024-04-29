#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include "Brain.hpp"

class Animal {
protected:
	std::string type;

public:
	virtual ~Animal();
	virtual void makeSound() const = 0;
	const std::string &getType() const;
};

#endif
