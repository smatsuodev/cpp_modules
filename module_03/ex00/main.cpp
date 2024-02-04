#include "ClapTrap.hpp"

int main() {
	ClapTrap c("Alice");

	c.attack("Bob");
	c.takeDamage(5);
	c.beRepaired(3);
}
