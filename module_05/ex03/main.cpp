#include <iostream>
#include "Intern.hpp"
#include <cassert>

int main() {
	Intern intern;

	{
		std::cout << "[Test 1] Make ShrubberyCreationForm" << std::endl;
		AForm *form = intern.makeForm("shrubbery creation", "target");
		assert(form->getName() == "ShrubberyCreationForm");
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 2] Make RobotomyRequestForm" << std::endl;
		AForm *form = intern.makeForm("robotomy request", "target");
		assert(form->getName() == "RobotomyRequestForm");
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 3] Make PresidentialPardonForm" << std::endl;
		AForm *form = intern.makeForm("presidential pardon", "target");
		assert(form->getName() == "PresidentialPardonForm");
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 4] Form doesn't exist" << std::endl;
		AForm *form = intern.makeForm("form doesn't exist", "target");
		assert(form == NULL);
	}
}
