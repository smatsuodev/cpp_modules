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
	virtual ~Animal();
	Animal &operator=(const Animal &animal);
	virtual void makeSound() const;
	const std::string &getType() const;
};

#endif
