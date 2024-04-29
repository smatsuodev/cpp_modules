#include "Bureaucrat.hpp"
#include <iostream>
#include <cassert>

int main() {
	{
		std::cout << "[Test 1] Regular test" << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 2);
		std::cout << bureaucrat << std::endl;
		Form form("Regular Form", 3, 3);
		std::cout << form << std::endl;
		assert(form.getIsSigned() == false);
		bureaucrat.signForm(form);
		assert(form.getIsSigned() == true);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 2] Grade too low to sign" << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 2);
		std::cout << bureaucrat << std::endl;
		Form form("Form", 1, 1);
		std::cout << form << std::endl;
		assert(form.getIsSigned() == false);
		bureaucrat.signForm(form);
		assert(form.getIsSigned() == false);
	}

	return 0;
}
