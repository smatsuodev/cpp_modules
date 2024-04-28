#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

//__attribute__((destructor()))
//static void destructor() {
//	system("leaks -q main");
//}

int main() {
	try {
		{
			const Animal *j = new Dog();
			const Animal *i = new Cat();
			delete j;//should not create a leak
			delete i;
		}

		{
			const Dog j;
			{
				const Dog i = j;
			}
		}

		{
			const Cat j;
			{
				const Cat i = j;
			}
		}
	} catch (std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
