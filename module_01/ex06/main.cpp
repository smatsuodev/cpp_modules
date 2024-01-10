#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	Harl harl;

	switch (Harl::get_level_index(argv[1])) {
		case 0:
			std::cout << "[DEBUG]\n";
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			std::cout << "[INFO]\n";
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:
			std::cout << "[WARNING]\n";
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			std::cout << "[ERROR]\n";
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
