#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
	name = fragTrap.name;
	hit_point = fragTrap.hit_point;
	energy_point = fragTrap.energy_point;
	attack_damage = fragTrap.attack_damage;
	return *this;
}

void FragTrap::attack(const std::string &target) {
	std::cout << "FragTrap " << name << " attacks " << target << " causing " << attack_damage
			  << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " says, \"High fives, guys!\"" << std::endl;
}
