#ifndef CPP_MODULES_CHARACTER_HPP
#define CPP_MODULES_CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string name;
	AMateria *inventory[4];

public:
	Character();
	Character(std::string const &name);
	Character(Character const &character);
	~Character();
	Character &operator=(Character const &character);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
