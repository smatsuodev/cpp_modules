#ifndef CPP_MODULES_FORM_HPP
#define CPP_MODULES_FORM_HPP

#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	class FormIsNotSigned : public std::exception {
	public:
		const char *what() const throw();
	};

	AForm();
	AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
	throw(GradeTooHighException, GradeTooLowException);
	AForm(const AForm &other);
	virtual ~AForm();
	AForm &operator=(const AForm &other);
	const std::string &getName() const;
	bool getIsSigned() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException);
	virtual void execute(Bureaucrat const &executor)
	const throw(GradeTooLowException, FormIsNotSigned) = 0;

private:
	const std::string name_;
	bool isSigned_;
	const unsigned int gradeToSign_;
	const unsigned int gradeToExecute_;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
