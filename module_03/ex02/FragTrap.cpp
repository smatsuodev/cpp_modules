#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	hit_point = 100;
	energy_point = 100;
	energy_point = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) {
	this->name = name;
	hit_point = 100;
	energy_point = 100;
	energy_point = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap) : ClapTrap(FragTrap) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap) {
	(ClapTrap) *this = (ClapTrap) FragTrap;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " says, \"High fives, guys!\"" << std::endl;
}
