#ifndef CPP_MODULES_SPAN_HPP
#define CPP_MODULES_SPAN_HPP

#include <vector>

class Span {
public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);
	void addNumber(int n);

	template<template<class, class> class T>
	void addNumbers(typename T<int, std::allocator<int> >::iterator begin,
					typename T<int, std::allocator<int> >::iterator end) {
		for (typename T<int, std::allocator<int> >::iterator it = begin; it != end; it++) {
			addNumber(*it);
		}
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

private:
	unsigned int capacity_;
	std::vector<int> numbers_;
};

#endif
