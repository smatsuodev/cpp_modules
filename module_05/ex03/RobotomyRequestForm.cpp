#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target_(other.target_) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)
const throw(GradeTooLowException, FormIsNotSigned) {
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!getIsSigned())
		throw FormIsNotSigned();
	srand(time(NULL));
	if (rand() % 2)
		std::cout << target_ << " has been robotomized" << std::endl;
	else
		std::cout << "failed to robotomize " << target_ << std::endl;
}
