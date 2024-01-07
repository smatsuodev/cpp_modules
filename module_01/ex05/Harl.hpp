#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
	void debug();
	void info();
	void warning();
	void error();

public:
	void complain(std::string level);
};

#endif
