#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
}
