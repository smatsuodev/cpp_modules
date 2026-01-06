#ifndef CPP_MODULES_RPN_HPP
#define CPP_MODULES_RPN_HPP

#include <stack>
#include <string>

void print_error();

class RPN {
public:
	RPN();
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &other);
	int calc(const std::string &input);

private:
	std::stack<int> stack_;
	void push(int value);
	int pop();
};

#endif
