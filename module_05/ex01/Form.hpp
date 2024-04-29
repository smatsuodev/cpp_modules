#ifndef CPP_MODULES_FORM_HPP
#define CPP_MODULES_FORM_HPP

#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form();
	Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	Form(const Form &other);
	~Form();
	Form &operator=(const Form &other);
	const std::string &getName() const;
	bool getIsSigned() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	void beSigned(const Bureaucrat &bureaucrat) throw(Form::GradeTooLowException);

private:
	std::string name_;
	bool isSigned_;
	unsigned int gradeToSign_;
	unsigned int gradeToExecute_;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
