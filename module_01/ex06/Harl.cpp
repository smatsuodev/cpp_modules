#include "Harl.hpp"
#include <iostream>

int Harl::get_level_index(std::string level) {
	static const char *levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (unsigned long i = 0; i < sizeof(levels) / sizeof(char *); i++) {
		if (level == levels[i])
			return (i);
	}
	return (-1);
}

void Harl::complain(std::string level) {
	static void (Harl::*fns[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int index = Harl::get_level_index(level);

	(this->*(fns[index]))();
}

void Harl::debug() {
	std::cout
		<< "\033[48;2;107;135;88m D \033[0m "
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< " I really do!"
		<< std::endl;
}

void Harl::info() {
	std::cout
		<< "\033[48;2;49;92;118m I \033[0m "
		<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!"
		<< " If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void Harl::warning() {
	std::cout
		<< "\033[48;2;187;181;42m \033[30mW \033[0m "
		<< "\033[38;2;187;181;42mI think I deserve to have some extra bacon for free."
		<< " I’ve been coming for years whereas you started working here since last month.\033[0m"
		<< std::endl;
}

void Harl::error() {
	std::cout
		<< "\033[48;2;207;90;84m \033[30mE \033[0m "
		<< "\033[38;2;207;90;84mThis is unacceptable! I want to speak to the manager now.\033[0m"
		<< std::endl;
}
