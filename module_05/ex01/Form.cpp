#include "Form.hpp"

Form::Form() : isSigned_(false), gradeToSign_(150), gradeToExecute_(150) {}

Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
throw(GradeTooHighException, GradeTooLowException): name_(name), isSigned_(false),
													gradeToSign_(gradeToSign),
													gradeToExecute_(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name_(other.name_), isSigned_(other.isSigned_),
								gradeToSign_(other.gradeToSign_),
								gradeToExecute_(other.gradeToExecute_) {}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		this->isSigned_ = other.isSigned_;
	}
	return *this;
}

const std::string &Form::getName() const {
	return name_;
}

bool Form::getIsSigned() const {
	return isSigned_;
}

unsigned int Form::getGradeToSign() const {
	return gradeToSign_;
}

unsigned int Form::getGradeToExecute() const {
	return gradeToExecute_;
}

void Form::beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException) {
	if (bureaucrat.getGrade() > gradeToSign_)
		throw Form::GradeTooLowException();
	isSigned_ = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "bureaucrat's grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "bureaucrat's grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << form.getName() << ", form required grade " << form.getGradeToSign() << " to sign, grade "
		<< form.getGradeToExecute() << " to execute";
	return out;
}
