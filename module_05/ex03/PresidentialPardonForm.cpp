#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), target_(other.target_) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor)
const throw(GradeTooLowException, FormIsNotSigned) {
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!getIsSigned())
		throw FormIsNotSigned();
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
