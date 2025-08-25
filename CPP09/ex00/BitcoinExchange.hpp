#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double> _prices;
	bool isValidDate(const std::string &date) const;
public:
	BitcoinExchange();
	BitcoinExchange(const std::map<std::string, double> prices);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void loadDatabase(const std::string &filename);
	double getRate(const std::string &date) const;
	void processInput(const std::string &filename) const;

};
