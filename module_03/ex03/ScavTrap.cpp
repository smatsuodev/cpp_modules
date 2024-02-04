#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
	name = scavTrap.name;
	hit_point = scavTrap.hit_point;
	energy_point = scavTrap.energy_point;
	attack_damage = scavTrap.attack_damage;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attack_damage
			  << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
