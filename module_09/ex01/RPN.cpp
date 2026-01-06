#include "RPN.hpp"
#include <climits>
#include <iostream>
#include <cstdlib>

void print_error() {
	std::cerr << "Error" << std::endl;
	exit(1);
}

void print_overflow() {
	std::cerr << "Overflow" << std::endl;
	exit(1);
}

RPN::RPN() {}

RPN::RPN(const RPN &other) : stack_(other.stack_) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		stack_ = other.stack_;
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
		if (c == '+') {
			if ((rhs > 0 && lhs > INT_MAX - rhs) || (rhs < 0 && lhs < INT_MIN - rhs))
				print_overflow();
			push(lhs + rhs);
		}
		else if (c == '-') {
			if ((rhs < 0 && lhs > INT_MAX + rhs) || (rhs > 0 && lhs < INT_MIN + rhs))
				print_overflow();
			push(lhs - rhs);
		}
		else if (c == '*') {
			if (lhs == 0 || rhs == 0) {
				push(0);
			} else {
				if ((lhs > 0 && ((rhs > 0 && lhs > INT_MAX / rhs) || (rhs < 0 && rhs < INT_MIN / lhs)))
					|| (lhs < 0 && ((rhs > 0 && lhs < INT_MIN / rhs) || (rhs < 0 && lhs < INT_MAX / rhs))))
					print_overflow();
				push(lhs * rhs);
			}
		}
		else if (c == '/') {
			if (rhs == 0)
				print_error();
			else if (lhs == INT_MIN && rhs == -1)
				print_overflow();
			else
				push(lhs / rhs);
		}
		else
			print_error();
	}
	return pop();
}

void RPN::push(int value) {
	stack_.push(value);
}

int RPN::pop() {
	if (stack_.size() == 0) print_error();
	int value = stack_.top();
	stack_.pop();
	return value;
}
