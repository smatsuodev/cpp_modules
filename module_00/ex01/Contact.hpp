#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact *ask_profile();
	void show_profile() const;

	const std::string &get_first_name() const;
	const std::string &get_last_name() const;
	const std::string &get_nickname() const;
};

#endif
