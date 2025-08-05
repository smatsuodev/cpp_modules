#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

static std::string trim(const std::string &input)
{
	std::size_t firstCharIdx = input.find_first_not_of(' ');
	std::size_t lastCharIdx = input.find_last_not_of(' ');
	return input.substr(firstCharIdx, lastCharIdx - firstCharIdx + 1);
}

static int getPrecision(const std::string &input)
{
	std::size_t periodPos = input.find('.');
	if (periodPos == std::string::npos)
		return 0;

	std::size_t len = trim(input.substr(periodPos)).length();
	if (input.find(".") != std::string::npos)
		len--;
	if (input.find("f") != std::string::npos)
		len--;
	return len;
}

static void convertAsChar(const std::string &input)
{
	std::cout << "char: ";
	if (input.length() == 1)
	{
		std::cout << "'" << static_cast<char>(input[0]) << "'" << std::endl;
		return;
	}

	try
	{
		int ascii = std::stoi(input);
		if (std::isprint(ascii))
			std::cout
				<< "'" << static_cast<char>(ascii) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

static void convertAsInt(const std::string &input)
{
	std::cout << "int: ";
	try
	{
		int value = std::stoi(input);
		std::cout << value << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

static void convertAsFloat(const std::string &input)
{
	std::cout << "float: ";
	try
	{
		float value = std::stof(input);
		int precision = getPrecision(input);
		if (precision < 1)
			precision = 1;
		std::cout << std::fixed << std::setprecision(precision) << value << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

static void convertAsDouble(const std::string &input)
{
	std::cout << "double: ";
	try
	{
		double value = std::stod(input);
		int precision = getPrecision(input);
		if (precision < 1)
			precision = 1;
		std::cout << std::fixed << std::setprecision(precision) << value << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input)
{
	convertAsChar(input);
	convertAsInt(input);
	convertAsFloat(input);
	convertAsDouble(input);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}
