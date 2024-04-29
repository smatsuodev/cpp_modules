#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void) other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
	(void) other;
	return *this;
}

static AForm *makeShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm *makePresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*formConstructors[3])(const std::string &) = {
		makeShrubberyCreationForm,
		makeRobotomyRequestForm,
		makePresidentialPardonForm};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return formConstructors[i](target);
		}
	}
	std::cout << "Form named '" << formName << "' doesn't exist" << std::endl;
	return NULL;
}
