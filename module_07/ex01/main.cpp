#include "iter.hpp"
#include <iostream>

void print(int value) {
	std::cout << value << std::endl;
}

int main() {
	int array[] = {1, 2, 3};
	iter(array, sizeof(array) / sizeof(int), print);

	int empty[] = {};
	iter(empty, sizeof(empty) / sizeof(int), print);
}
