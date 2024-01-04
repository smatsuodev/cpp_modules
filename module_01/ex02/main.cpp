#include <string>
#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "address of str:    " << &str << "\n"
			  << "held by stringPTR: " << stringPTR << "\n"
			  << "held by stringREF: " << &stringREF << "\n\n";

	std::cout << "value of str:         " << str << "\n"
			  << "pointed by stringPTR: " << *stringPTR << "\n"
			  << "pointed by stringREF: " << stringREF << std::endl;
}
