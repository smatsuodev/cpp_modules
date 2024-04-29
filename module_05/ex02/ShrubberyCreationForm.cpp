#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target_(other.target_) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
const throw(GradeTooLowException, FormIsNotSigned) {
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!getIsSigned())
		throw FormIsNotSigned();
	std::ofstream target(target_ + "_shrubbery");
	target << "              v .   ._, |_  .,\n"
			  "           `-._\\/  .  \\ /    |/_\n"
			  "               \\\\  _\\, y | \\//\n"
			  "         _\\_.___\\\\, \\\\/ -.\\||\n"
			  "           `7-,--.`._||  / / ,\n"
			  "           /'     `-. `./ / |/_.'\n"
			  "                     |    |//\n"
			  "                     |_    /\n"
			  "                     |-   |\n"
			  "                     |   =|\n"
			  "                     |    |\n"
			  "--------------------/ ,  . \\--------._" << std::endl;
}
