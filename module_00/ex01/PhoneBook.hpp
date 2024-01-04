#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {
	static const int SIZE = 8;

	Contact contacts[SIZE];
	int next_contact_index;
	int num_of_contacts;

public:
	PhoneBook();

	void add_contact(const Contact &contact);
	void show_contacts() const;
	void show_choose_contact_dialog() const;
};

#endif
