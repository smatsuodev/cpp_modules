#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	{
		std::cout << "[Test 1] Regular case (ShrubberyCreationForm)" << std::endl;
		Bureaucrat bureaucrat("John", 3);
		ShrubberyCreationForm form("home");
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 2] Regular case (RobotomyRequestForm)" << std::endl;
		Bureaucrat bureaucrat("John", 3);
		RobotomyRequestForm form("home");
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 3] Regular case (PresidentialPardonForm)" << std::endl;
		Bureaucrat bureaucrat("John", 3);
		PresidentialPardonForm form("home");
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 4] Form is not signed (ShrubberyCreationForm)" << std::endl;
		Bureaucrat bureaucrat("John", 3);
		ShrubberyCreationForm form("home");
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 5] Form is not signed (RobotomyRequestForm)" << std::endl;
		Bureaucrat bureaucrat("John", 3);
		RobotomyRequestForm form("home");
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 6] Form is not signed (PresidentialPardonForm)" << std::endl;
		Bureaucrat bureaucrat("John", 3);
		PresidentialPardonForm form("home");
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 7] Grade too low to execute (ShrubberyCreationForm)" << std::endl;
		Bureaucrat supervisor("Supervisor", 1);
		Bureaucrat bureaucrat("John", 146);
		ShrubberyCreationForm form("home");
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		supervisor.signForm(form);
		bureaucrat.executeForm(form);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 8] Grade too low to execute (RobotomyRequestForm)" << std::endl;
		Bureaucrat supervisor("Supervisor", 1);
		Bureaucrat bureaucrat("John", 146);
		RobotomyRequestForm form("home");
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		supervisor.signForm(form);
		bureaucrat.executeForm(form);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 9] Grade too low to execute (PresidentialPardonForm)" << std::endl;
		Bureaucrat supervisor("Supervisor", 1);
		Bureaucrat bureaucrat("John", 146);
		PresidentialPardonForm form("home");
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		supervisor.signForm(form);
		bureaucrat.executeForm(form);
	}
}
