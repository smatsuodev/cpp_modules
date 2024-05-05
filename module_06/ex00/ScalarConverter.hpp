#ifndef CPP_MODULES_SCALARCONVERTER_HPP
#define CPP_MODULES_SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
	static void convert(const std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);
};

#endif
