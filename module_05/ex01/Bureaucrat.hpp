#ifndef CPP_MODULES_BUREAUCRAT_HPP
#define CPP_MODULES_BUREAUCRAT_HPP

#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
public:
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string &name, unsigned int grade)
	throw(GradeTooHighException, GradeTooLowException);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);
	const std::string &getName() const;
	unsigned int getGrade() const;
	void incrementGrade() throw(GradeTooHighException);
	void decrementGrade() throw(GradeTooLowException);
	void signForm(Form &form) const;

private:
	const std::string name_;
	unsigned int grade_;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
