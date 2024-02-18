#include "PhoneBook.hpp"
#include "utils.hpp"

#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	next_contact_index = 0;
	num_of_contacts = 0;
}

void PhoneBook::add_contact(const Contact &contact) {
	contacts[next_contact_index] = contact;

	if (next_contact_index + 1 == SIZE)
		next_contact_index = 0;
	else
		next_contact_index++;

	if (num_of_contacts < SIZE)
		num_of_contacts++;
}

static void print_row(const std::string data[4]) {
	for (int i = 0; i < 4; i++) {
		if (i == 0)
			std::cout << '|';

		// truncate
		if (data[i].length() > 10)
			std::cout << data[i].substr(0, 9) << '.';
		else
			std::cout << std::right << std::setw(10) << std::setfill(' ')
					  << data[i];

		std::cout << '|';
	}
	std::cout << "\n";
}

void PhoneBook::show_contacts() const {
	std::string columns[] = {"index", "first name", "last name", "nickname"};

	print_row(columns);

	for (int i = 0; i < num_of_contacts; i++) {
		const Contact *contact = &contacts[i];
		std::string data[] = {std::to_string(i),
							  contact->get_first_name(),
							  contact->get_last_name(),
							  contact->get_nickname()};

		print_row(data);
	}
}

void PhoneBook::show_choose_contact_dialog() const {
	std::string input;
	ask_question("Choose index", input);

	if (input.size() != 1 || input[0] < '0' || input[0] > '9') {
		close_dialog_with_error("wrong index");
		return;
	}

	int index = std::stoi(input);
	if (index >= num_of_contacts) {
		close_dialog_with_error("out of range");
		return;
	}

	close_dialog_with_ok();

	contacts[index].show_profile();
}
