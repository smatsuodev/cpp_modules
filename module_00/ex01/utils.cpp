#include <iostream>

std::string ask_question(const std::string &question, std::string &ans) {
	if (std::cin.eof())
		exit(0);

	do {
		std::cout << "\033[38;2;0;198;200m? \033[0;1m" << question
				  << "\033[0m\033[38;2;104;104;104m › \033[0m";
		if (!std::getline(std::cin, ans))
			exit(0);
	} while (ans.empty());

	return ans;
}

void close_dialog_with_ok() {
	std::cout << "\x1b[A\r\033[38;2;3;195;0m✔\033[0m" << std::endl;
}

void close_dialog_with_error(const std::string &message) {
	std::cout << "\x1b[A\r\033[38;2;200;26;1m✖\033[0m" << std::endl;
	std::cout << "\033[38;2;200;26;1mError: " << message << "\033[0m" << std::endl;
}
