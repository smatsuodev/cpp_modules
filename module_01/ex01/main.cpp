#include "Zombie.hpp"

int main() {
	int n = 3;
	Zombie *horde = zombieHorde(n, "Mob");

	for (int i = 0; i < n; i++)
		horde->announce();

	delete[] horde;
}
