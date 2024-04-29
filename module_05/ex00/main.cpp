#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	{
		std::cout << "Test 1 - Regular case" << std::endl;
		Bureaucrat bureaucrat("John", 3);
		std::cout << bureaucrat << std::endl;
		try {
			bureaucrat.incrementGrade();
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << bureaucrat << std::endl;
		try {
			bureaucrat.decrementGrade();
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << bureaucrat << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Test 2 - Grade too high in constructor" << std::endl;
		try {
			Bureaucrat bureaucrat("John", 0);
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "Test 3 - Grade too high in incrementGrade" << std::endl;
		Bureaucrat bureaucrat("John", 1);
		try {
			bureaucrat.incrementGrade();
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "Test 4 - Grade too low in constructor" << std::endl;
		try {
			Bureaucrat bureaucrat("John", 151);
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "Test 5 - Grade too low in decrementGrade" << std::endl;
		Bureaucrat bureaucrat("John", 150);
		try {
			bureaucrat.decrementGrade();
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
