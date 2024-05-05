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
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

private:
	unsigned int capacity_;
	std::vector<int> numbers_;
};

#endif
