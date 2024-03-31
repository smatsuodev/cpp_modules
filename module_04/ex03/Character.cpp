#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() {}

Character::Character(const std::string &name) : name(name) {}

Character::Character(const Character &other) : name(other.name) {}

Character::~Character() {}

Character &Character::operator=(const Character &other) {
	name = other.name;
	return *this;
}

const std::string &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < SLOT_SIZE; i++) {
		if (slot[i] == NULL) {
			slot[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < SLOT_SIZE) {
		slot[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= SLOT_SIZE)
		return;

	slot[idx]->use(target);
}
