#include "Span.hpp"
#include <climits>
#include <cassert>
#include <stdexcept>

#define ASSERT_EXCEPT(expr, exception) \
    {                          \
        bool hasThrew = false;                       \
        try { \
            expr; \
        } catch (const exception &e) { \
            hasThrew = true; \
        }                   \
        assert(hasThrew); \
    }

int main() {
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		assert(sp.shortestSpan() == 2);
		assert(sp.longestSpan() == 14);
	}
	{
		Span sp(10000);
		for (int i = 1; i <= 10000; i++) {
			sp.addNumber(i);
		}
		assert(sp.shortestSpan() == 1);
		assert(sp.longestSpan() == 1);
	}
	{
		Span sp(10000);
		for (int i = 1; i <= 10000; i++) {
			sp.addNumber(i);
		}
		ASSERT_EXCEPT(sp.addNumber(1), std::runtime_error);
	}
	{
		Span sp(10000);
		ASSERT_EXCEPT(sp.shortestSpan(), std::runtime_error);
		ASSERT_EXCEPT(sp.longestSpan(), std::runtime_error);
		sp.addNumber(0);
		ASSERT_EXCEPT(sp.shortestSpan(), std::runtime_error);
		ASSERT_EXCEPT(sp.longestSpan(), std::runtime_error);
	}
	{
		Span sp(3);
		std::vector<int> numbers;
		numbers.push_back(INT_MAX);
		numbers.push_back(INT_MAX);
		numbers.push_back(INT_MIN);
		sp.addNumbers<std::vector>(numbers.begin(), numbers.end());
		assert(sp.shortestSpan() == 0);
		assert(sp.longestSpan() == UINT_MAX);
	}
	return 0;
}
