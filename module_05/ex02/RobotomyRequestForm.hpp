#ifndef CPP_MODULES_ROBOTOMYREQUESTFORM_HPP
#define CPP_MODULES_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	void execute(const Bureaucrat &executor)
	const throw(GradeTooLowException, FormIsNotSigned);

private:
	std::string target_;
};

#endif
