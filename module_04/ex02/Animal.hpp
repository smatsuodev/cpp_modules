#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include "Brain.hpp"

class Animal {
protected:
	Brain *brain;
	std::string type;

public:
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &animal);
	virtual ~Animal() = 0;
	Animal &operator=(const Animal &animal);
	virtual void makeSound() const = 0;
	const std::string &getType() const;
};

#endif
