#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	std::string input = (argc == 2) ? argv[1] : "";
	std::map<std::string, double> prices;

	BitcoinExchange btcExchange;

	try {
		btcExchange.loadDatabase("data.csv");
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	};

	try {
		btcExchange.processInput(input);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
