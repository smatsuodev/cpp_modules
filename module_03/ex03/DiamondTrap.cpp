#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() {
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	hit_point = FragTrap::hit_point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const std::string &name) : FragTrap(name), ScavTrap(name) {
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	hit_point = FragTrap::hit_point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : FragTrap(diamondTrap) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		name = other.name;
		hit_point = other.hit_point;
		energy_point = other.energy_point;
		attack_damage = other.attack_damage;
	}
	return *this;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
