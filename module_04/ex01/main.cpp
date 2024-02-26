#include "Dog.hpp"
#include "Cat.hpp"

__attribute__((destructor()))
static void destructor() {
	system("leaks -q main");
}

int main() {
	Animal *animals[6] = {new Dog, new Dog, new Dog, new Cat, new Cat, new Cat};
	Dog src_dog;
	Dog dst_dog = src_dog;
	Cat src_cat;
	Cat dst_cat = src_cat;

	for (int i = 0; i < 6; i++)
		delete animals[i];

	return 0;
}
