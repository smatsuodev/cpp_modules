#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

static void convertAsChar(const std::string &input) {
	int i;
	std::stringstream ss;
	ss << input;
	ss >> i;

	// print as char
	std::cout << "char: ";
	if (isprint(i))
		std::cout << static_cast<char>(i);
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	// print as int
	std::cout << "int: " << i << std::endl;

	// print as float
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << 'f'
			  << std::endl;

	// print as double
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i)
			  << std::endl;
}

static void convertAsInt(const std::string &input) {
	int i;
	std::stringstream ss;
	ss << input;
	ss >> i;

	// print as char
	std::cout << "char: impossible" << std::endl;

	// print as int
	std::cout << "int: " << i << std::endl;

	// print as float
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << 'f'
			  << std::endl;

	// print as double
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i)
			  << std::endl;
}

static void convertAsFloat(const std::string &input) {
	float f;
	std::stringstream ss;
	ss << input.substr(0, input.length() - 1);
	ss >> f;

	// print as char
	std::cout << "char: impossible" << std::endl;

	// print as int
	std::cout << "int: " << static_cast<int>(f) << std::endl;

	if (input.find("inf") != std::string::npos || input.find("nan") != std::string::npos) {
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		return;
	}

	int precision = input.size() - input.find('.') - 2;
	// print as float
	std::cout << "float: " << std::fixed << std::setprecision(precision) << f << 'f' << std::endl;

	// print as double
	std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(f)
			  << std::endl;
}

static void convertAsDouble(const std::string &input) {
	float f;
	double d;
	std::stringstream ss;
	ss << input << ' ' << input;
	ss >> d >> f;

	// print as char
	std::cout << "char: impossible" << std::endl;

	// print as int
	std::cout << "int: " << static_cast<int>(d) << std::endl;

	if (input.find("inf") != std::string::npos || input.find("nan") != std::string::npos) {
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return;
	}

	// print as float
	int precision = input.size() - input.find('.') - 1;
	if (!ss) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(precision)
				  << static_cast<float>(d)
				  << 'f'
				  << std::endl;
	}

	// print as double
	std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
	std::stringstream ss;
	ss << input << ' ' << input;
	double inputAsDouble;
	ss >> inputAsDouble;
	bool didOverflowAsDouble = !ss;
	int inputAsInt;
	ss >> inputAsInt;
	bool didOverflowAsInt = !ss;

	if (input.size()==1&&isalpha(input[0])) {
		std::cout << "char: " << input[0] << std::endl
				  << "int: impossible\n"
				  << "float: impossible\n"
				  << "double: impossible" << std::endl;
		return;
	}
	if (input.find("inff") != std::string::npos || input.find("nanf") != std::string::npos) {
		convertAsFloat(input);
		return;
	}
	if (input.find("inf") != std::string::npos || input.find("nan") != std::string::npos) {
		convertAsDouble(input);
		return;
	}
	if (input.back() == 'f') {
		convertAsFloat(input);
		return;
	}
	if (input.find('.') != std::string::npos) {
		if (didOverflowAsDouble)
			std::cout << "char: impossible\n"
					  << "int: impossible\n"
					  << "float: impossible\n"
					  << "double: impossible" << std::endl;
		else
			convertAsDouble(input);
		return;
	}
	if (didOverflowAsInt)
		convertAsFloat(input);
	else if (CHAR_MIN <= inputAsInt && inputAsInt <= CHAR_MAX)
		convertAsChar(input);
	else
		convertAsInt(input);
}
