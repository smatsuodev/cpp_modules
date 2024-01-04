#include <iostream>

std::string ask_question(const std::string &question, std::string &ans) {
	if (std::cin.eof())
		exit(0);

	do {
		std::cout << "\033[38;2;0;198;200m? \033[0;1m" << question
				  << "\033[0m\033[38;2;104;104;104m › \033[0m";
	} while (std::getline(std::cin, ans) && ans.empty());

	std::cout << "\x1b[A\r\033[38;2;3;195;0m✔\033[0m" << std::endl;

	return ans;
}
