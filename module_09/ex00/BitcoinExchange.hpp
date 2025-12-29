#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    // Helper functions
    std::string trim(const std::string& str);
    bool        isValidDate(const std::string& date);
    bool        isValidValue(const float& value);
    float       getExchangeRate(const std::string& date);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const char* filename);
    void processInput(const char* filename);
};

#endif
