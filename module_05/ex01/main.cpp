#include "Bureaucrat.hpp"
#include <iostream>
#include <cassert>

#define ASSERT_EXCEPT(expr, exception) \
    {                          \
        bool hasThrew = false;                       \
        try { \
            expr; \
        } catch (const exception &e) { \
            std::cout << e.what() << std::endl;             \
            hasThrew = true; \
        }                   \
        assert(hasThrew); \
    }

int main() {
	{
		std::cout << "[Test 1] Regular test" << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 2);
		Form form("Regular Form", 3, 3);
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		assert(form.getIsSigned() == false);
		bureaucrat.signForm(form);
		assert(form.getIsSigned() == true);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 2] Grade too low to sign" << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 2);
		Form form("Form", 1, 1);
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		assert(form.getIsSigned() == false);
		bureaucrat.signForm(form);
		assert(form.getIsSigned() == false);
	}

	std::cout<< "---------------------" << std::endl;

	{
		std::cout << "[Test 3] Grade to sign too high in constructor" << std::endl;
		ASSERT_EXCEPT(Form form("Form", 0, 1), Form::GradeTooHighException);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 4] Grade to execute too high in constructor" << std::endl;
		ASSERT_EXCEPT(Form form("Form", 1, 0), Form::GradeTooHighException);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 5] Grade to sign too low in constructor" << std::endl;
		ASSERT_EXCEPT(Form form("Form", 151, 1), Form::GradeTooLowException);
	}

	std::cout << "---------------------" << std::endl;

	{
		std::cout << "[Test 6] Grade to execute too low in constructor" << std::endl;
		ASSERT_EXCEPT(Form form("Form", 1, 151), Form::GradeTooLowException);
	}

	return 0;
}
