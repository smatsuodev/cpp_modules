#ifndef CPP_MODULES_SHRUBBERYCREATIONFORM_HPP
#define CPP_MODULES_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	void execute(Bureaucrat const &executor)
	const throw(GradeTooLowException, FormIsNotSigned);

private:
	std::string target_;
};

#endif
