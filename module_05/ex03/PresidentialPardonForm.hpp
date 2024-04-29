#ifndef CPP_MODULES_PRESIDENTIALPARDONFORM_HPP
#define CPP_MODULES_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	void execute(const Bureaucrat &executor)
	const throw(GradeTooLowException, FormIsNotSigned);

private:
	std::string target_;
};

#endif
