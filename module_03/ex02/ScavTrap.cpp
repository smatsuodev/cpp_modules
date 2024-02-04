#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {
	hit_point = 100;
	energy_point = 50;
	energy_point = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) {
	this->name = name;
	hit_point = 100;
	energy_point = 50;
	energy_point = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
	(ClapTrap) *this = (ClapTrap) scavTrap;
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
