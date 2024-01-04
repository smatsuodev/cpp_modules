#include <iostream>
#include "PhoneBook.hpp"

#define PROMPT "> "

static bool prompt() {
	return std::cout << PROMPT << std::flush;
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (prompt() && std::getline(std::cin, command)) {
		if (command == "ADD") {
			Contact contact;

			contact.ask_profile();
			phoneBook.add_contact(contact);
		} else if (command == "SEARCH") {
			phoneBook.show_contacts();
			phoneBook.show_choose_contact_dialog();
		} else if (command == "EXIT") {
			return 0;
		}
	}
}
