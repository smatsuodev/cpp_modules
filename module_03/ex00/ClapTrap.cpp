#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : hit_point(10), energy_point(10), attack_damage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: name(name), hit_point(10), energy_point(10), attack_damage(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << "Copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
	name = clapTrap.name;
	hit_point = clapTrap.hit_point;
	energy_point = clapTrap.energy_point;
	attack_damage = clapTrap.attack_damage;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage
			  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << name << " is repaired " << amount << " hit points!" << std::endl;
}
