#include "ScalarConverter.hpp"
#include <iostream>

int main() {
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	ScalarConverter::convert("3.14f");
	std::cout << std::endl;
	ScalarConverter::convert("3.14");
	std::cout << std::endl;
	ScalarConverter::convert("a");
	return 0;
}
