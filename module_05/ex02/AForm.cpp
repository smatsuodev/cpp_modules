#include "AForm.hpp"

AForm::AForm() : isSigned_(false), gradeToSign_(150), gradeToExecute_(150) {}

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
throw(GradeTooHighException, GradeTooLowException): name_(name), isSigned_(false),
													gradeToSign_(gradeToSign),
													gradeToExecute_(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name_(other.name_), isSigned_(other.isSigned_),
								   gradeToSign_(other.gradeToSign_),
								   gradeToExecute_(other.gradeToExecute_) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		this->isSigned_ = other.isSigned_;
	}
	return *this;
}

const std::string &AForm::getName() const {
	return name_;
}

bool AForm::getIsSigned() const {
	return isSigned_;
}

unsigned int AForm::getGradeToSign() const {
	return gradeToSign_;
}

unsigned int AForm::getGradeToExecute() const {
	return gradeToExecute_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException) {
	if (bureaucrat.getGrade() > gradeToSign_)
		throw AForm::GradeTooLowException();
	isSigned_ = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "bureaucrat's grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "bureaucrat's grade is too low";
}

const char *AForm::FormIsNotSigned::what() const throw() {
	return "form attempted to execute is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << form.getName() << ", form required grade " << form.getGradeToSign() << " to sign, grade "
		<< form.getGradeToExecute() << " to execute";
	return out;
}
