#ifndef CPP_MODULES_CURE_HPP
#define CPP_MODULES_CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(Cure const &cure);
	~Cure();
	Cure &operator=(Cure const &cure);
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
