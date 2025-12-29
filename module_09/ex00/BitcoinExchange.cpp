#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t");
	if (std::string::npos == first) return str;
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	char dash1, dash2;
	std::stringstream ss(date);

	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail() || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28)) return false;
	}
	return true;
}

void BitcoinExchange::loadDatabase(const char* filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) continue;

		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);

		float rate = static_cast<float>(std::atof(rateStr.c_str()));
		_database[date] = rate;
	}
	file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date) {
	std::map<std::string, float>::iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date) {
		return it->second;
	}

	if (it == _database.begin()) {
		return it->second;
	}

	--it;
	return it->second;
}

void BitcoinExchange::processInput(const char* filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line);
	if (line != "date | value") {
		std::cerr << "Error: bad input => " << line << std::endl;
		exit(1);
	}

	while (std::getline(file, line)) {
		if (line.empty()) continue;

		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		float value = static_cast<float>(std::atof(valueStr.c_str()));

		// Specific requirements for value errors
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float rate = getExchangeRate(date);
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	file.close();
}
