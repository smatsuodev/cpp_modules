#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	static const int SLOT_SIZE = 4;

	std::string name;
	AMateria *slot[SLOT_SIZE];

public:
	Character();
	Character(const std::string &name);
	Character(const Character &character);
	~Character();
	Character &operator=(const Character &character);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
