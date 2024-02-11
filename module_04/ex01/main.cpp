#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	Animal *animals[6] = {new Dog, new Dog, new Dog, new Cat, new Cat, new Cat};
	Animal *copy = animals[0];

	for (int i = 0; i < 6; i++)
		delete animals[i];

	delete copy;

	return 0;
}
