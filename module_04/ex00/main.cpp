#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

//__attribute__((destructor))
//static void destructor() {
//	system("leaks -q main");
//}

int main() {
	try {
		{
			const Animal *meta = new Animal();
			const Animal *j = new Dog();
			const Animal *i = new Cat();

			std::cout << j->getType() << std::endl;
			std::cout << i->getType() << std::endl;
			i->makeSound(); //will output the cat sound!
			j->makeSound();
			meta->makeSound();

			/** Wrong version **/
			const WrongAnimal *wrongMeta = new WrongAnimal();
			const WrongAnimal *wrongCat = new WrongCat();

			std::cout << wrongCat->getType() << std::endl;
			wrongMeta->makeSound();
			wrongCat->makeSound(); // will not output the cat sound!

			delete meta;
			delete i;
			delete j;
			delete wrongMeta;
			delete wrongCat;
		}

		std::cout << std::endl;

		{
			const Dog i;
			const Dog j = i;

			std::cout << i.getType() << std::endl;
			std::cout << j.getType() << std::endl;
			i.makeSound();
		}

		std::cout << std::endl;

		{
			const Cat i;
			const Cat j = i;

			std::cout << i.getType() << std::endl;
			std::cout << j.getType() << std::endl;
			i.makeSound();
		}
	} catch (std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
