#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include "Brain.hpp"

class Animal {
protected:
	std::string type;

public:
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);
	virtual void makeSound() const;
	const std::string &getType() const;
};

#endif
