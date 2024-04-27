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
//	std::cout << std::endl;
//	{
//		Ice ice;
//		Cure cure;
//		std::cout << "'" << ice.getType() << "' must be ice" << std::endl;
//		std::cout << "'" << cure.getType() << "' must be cure" << std::endl;
//	}
//	std::cout << std::endl;
//	{
//		Character me("me");
//		std::cout << "'" << me.getName() << "' must be me" << std::endl;
//	}
	return 0;
}
