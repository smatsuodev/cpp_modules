#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	std::string type;
	Brain *brain;

public:
	Cat();
	Cat(const Cat &cat);
	~Cat();
	Cat &operator=(const Cat &other);
	void makeSound() const;
	const std::string & getType() const;
};

#endif
