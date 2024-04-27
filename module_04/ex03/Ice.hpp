#ifndef CPP_MODULES_ICE_HPP
#define CPP_MODULES_ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(Ice const &ice);
	~Ice();
	Ice &operator=(Ice const &ice);
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
