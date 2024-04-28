#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

//__attribute__((destructor))
//static void destructor() {
//	system("leaks -q main");
//}

int main() {
	try {
		{
			IMateriaSource *src = new MateriaSource();
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());

			ICharacter *me = new Character("me");
			AMateria *ice = src->createMateria("ice");
			AMateria *cure = src->createMateria("cure");

			me->equip(ice);
			me->equip(cure);
			ICharacter *bob = new Character("bob");
			me->use(0, *bob);
			me->use(1, *bob);
			me->unequip(0);
			std::cout << "unequip(0)" << std::endl;
			me->use(1, *bob);
			AMateria *cure2 = src->createMateria("cure");
			me->equip(cure2);
			me->use(0, *bob);
			me->use(1, *bob);
			delete bob;
			delete me;
			delete src;
			delete ice;
		}
	} catch (std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
