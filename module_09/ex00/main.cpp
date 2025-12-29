#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    btc.loadDatabase("data.csv");

    btc.processInput(argv[1]);

    return 0;
}
