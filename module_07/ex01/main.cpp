#include "iter.hpp"
#include <iostream>

void print_int(const int& value) {
	std::cout << value << std::endl;
}

void inc(int& value) {
	value++;
}

int main() {
	std::cout << "---- Test with [1, 2, 3] ----" << std::endl;
	int array[] = {1, 2, 3};
	iter(array, sizeof(array) / sizeof(int), print_int);
	std::cout << "--- Increment array above ---" << std::endl;
	iter(array, sizeof(array) / sizeof(int), inc);
	iter(array, sizeof(array) / sizeof(int), print_int);
	std::cout << "-----------------------------\n" << std::endl;

	std::cout << "--- Test with empty array ---" << std::endl;
	int empty[] = {};
	iter(empty, sizeof(empty) / sizeof(int), print_int);
	std::cout << "-----------------------------" << std::endl;
}
