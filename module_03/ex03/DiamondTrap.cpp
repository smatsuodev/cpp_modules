#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() {
	hit_point = FragTrap::hit_point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ScavTrap(name), FragTrap(name) {
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	hit_point = FragTrap::hit_point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : FragTrap(diamondTrap) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	name = diamondTrap.name;
	hit_point = diamondTrap.hit_point;
	energy_point = diamondTrap.energy_point;
	attack_damage = diamondTrap.attack_damage;
	return *this;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
