#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	std::string name;
	int hit_point;
	int energy_point;
	int attack_damage;

public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &diamondTrap);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &other);
	void attack(const std::string &target);
	void whoAmI();
};

#endif
