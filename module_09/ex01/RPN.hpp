#ifndef CPP_MODULES_RPN_HPP
#define CPP_MODULES_RPN_HPP

#include <string>
#include <map>

void print_error();

class RPN {
public:
	RPN();
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &other);
	int calc(const std::string &input);

private:
	std::map<unsigned int, int> stack_;
	size_t top_;
	void push(int value);
	int pop();
};

#endif
