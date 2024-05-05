#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) print_error();

	RPN rpn;
	std::cout << rpn.calc(argv[1]) << std::endl;
}
