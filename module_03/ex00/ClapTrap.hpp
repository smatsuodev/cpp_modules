#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
	std::string name;
	int hit_point;
	int energy_point;
	int attack_damage;

public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &clapTrap);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
