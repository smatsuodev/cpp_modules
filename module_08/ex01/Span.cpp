#include "Span.hpp"

Span::Span() : capacity_(0) {}

Span::Span(unsigned int n) : capacity_(n) {}

Span::Span(const Span &other) : capacity_(other.capacity_), numbers_(other.numbers_) {
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		capacity_ = other.capacity_;
		numbers_ = other.numbers_;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (numbers_.size() == capacity_)
		throw std::runtime_error("span is fulfilled");
	numbers_.push_back(n);
}

unsigned int Span::shortestSpan() const {
	unsigned int result = UINT_MAX;
	if (numbers_.size() <= 1)
		throw std::runtime_error("no span found");
	for (unsigned int i = 1; i < numbers_.size(); i++) {
		int a = numbers_[i];
		int b = numbers_[i - 1];
		unsigned int span = a < b ? b - a : a - b;
		if (span < result)
			result = span;
	}
	return result;
}

unsigned int Span::longestSpan() const {
	unsigned int result = 0;
	if (numbers_.size() <= 1)
		throw std::runtime_error("no span found");
	for (unsigned int i = 1; i < numbers_.size(); i++) {
		int a = numbers_[i];
		int b = numbers_[i - 1];
		unsigned int span = a < b ? b - a : a - b;
		if (span > result)
			result = span;
	}
	return result;
}
