#include "Character.hpp"

Character::Character(std::string const &name) : name(name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(Character const &character) : name(character.name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = character.inventory[i]->clone();
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete inventory[i];
}

Character &Character::operator=(Character const &character) {
	if (this != &character) {
		name = character.name;
		for (int i = 0; i < 4; i++) {
			delete inventory[i];
			inventory[i] = character.inventory[i]->clone();
		}
	}
	return *this;
}

std::string const &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
		inventory[idx]->use(target);
}
