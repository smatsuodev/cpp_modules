#include "ScalarConverter.hpp"
#include <iostream>

int main()
{
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
	std::cout << std::endl;
	ScalarConverter::convert("ab");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	return 0;
}
