#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("") {}

Zombie::Zombie(const std::string &name) : name(name) {}

Zombie::~Zombie() {
	std::cout << "destructor called for '" << name << "'" << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
	Zombie::name = name;
}
