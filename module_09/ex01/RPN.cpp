#include "RPN.hpp"
#include <map>
#include <iostream>

void print_error() {
	std::cout << "Error" << std::endl;
	exit(1);
}

RPN::RPN() : top_(0) {}

RPN::RPN(const RPN &other) : stack_(other.stack_), top_(other.top_) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		stack_ = other.stack_;
		top_ = other.top_;
	}
	return *this;
}

int RPN::calc(const std::string &input) {
	for (size_t i = 0; i < input.size(); ++i) {
		char c = input[i];
		if (('\t' <= c && c <= '\r') || c == ' ') continue;

		if (isdigit(c)) {
			push(c - '0');
			continue;
		}

		int rhs = pop();
		int lhs = pop();
		if (c == '+')
			push(lhs + rhs);
		else if (c == '-')
			push(lhs - rhs);
		else if (c == '*')
			push(lhs * rhs);
		else if (c == '/')
			push(lhs / rhs);
		else
			print_error();
	}
	if (top_ != 1) print_error();
	return pop();
}

void RPN::push(int value) {
	stack_[top_++] = value;
}

int RPN::pop() {
	if (top_ == 0) print_error();
	return stack_[--top_];
}
