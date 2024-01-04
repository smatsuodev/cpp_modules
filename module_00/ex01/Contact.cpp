#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"

Contact *Contact::ask_profile() {
	ask_question("First name", first_name);
	ask_question("Last name", last_name);
	ask_question("Nickname", nickname);
	ask_question("Phone number", phone_number);
	ask_question("Darkest secret", darkest_secret);

	return this;
}

const std::string &Contact::get_first_name() const {
	return first_name;
}

const std::string &Contact::get_last_name() const {
	return last_name;
}

const std::string &Contact::get_nickname() const {
	return nickname;
}

void Contact::show_profile() const {
	std::cout << "First name: " << first_name << "\n";
	std::cout << "Last name: " << last_name << "\n";
	std::cout << "Nickname: " << nickname << "\n";
	std::cout << "Phone number: " << phone_number << "\n";
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}
