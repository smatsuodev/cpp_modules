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
		std::cout << "Test 1 - Regular case" << std::endl;
		Bureaucrat bureaucrat("John", 3);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		assert(bureaucrat.getGrade() == 2);
		bureaucrat.decrementGrade();
		assert(bureaucrat.getGrade() == 3);
		std::cout << bureaucrat << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Test 2 - Grade too high in constructor" << std::endl;
		ASSERT_EXCEPT(Bureaucrat("John", 0), Bureaucrat::GradeTooHighException);
	}

	std::cout << std::endl;

	{
		std::cout << "Test 3 - Grade too high in incrementGrade" << std::endl;
		Bureaucrat bureaucrat("John", 1);
		ASSERT_EXCEPT(bureaucrat.incrementGrade(), Bureaucrat::GradeTooHighException);
	}

	std::cout << std::endl;

	{
		std::cout << "Test 4 - Grade too low in constructor" << std::endl;
		ASSERT_EXCEPT(Bureaucrat("John", 151), Bureaucrat::GradeTooLowException);
	}

	std::cout << std::endl;

	{
		std::cout << "Test 5 - Grade too low in decrementGrade" << std::endl;
		Bureaucrat bureaucrat("John", 150);
		ASSERT_EXCEPT(bureaucrat.decrementGrade(), Bureaucrat::GradeTooLowException);
	}
	return 0;
}
