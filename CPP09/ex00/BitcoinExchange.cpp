#include "BitcoinExchange.hpp"
#include <iostream>
#include <cctype>
#include <ctime>
#include <cstring>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>

//[ HELPERS

static double toDouble(const std::string &value) {
	std::istringstream iss(value);
	double val;
	iss >> val;
	return val;
}

static std::string trim(const std::string &str) {
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(static_cast<unsigned char>(str[start]))) {
		++start;
	}
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) {
		--end;
	}
	return str.substr(start, end - start);
}

//] HELPERS

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::map<std::string, double> prices) {
	_prices = prices;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _prices(other._prices) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	_prices = other._prices;
	return *this;
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
	struct tm timeStruct;
	memset(&timeStruct, 0, sizeof(timeStruct));
	char *endPtr = strptime(date.c_str(), "%Y-%m-%d", &timeStruct);
	if (endPtr == NULL || *endPtr != 0) {
		std::cerr << "Error: invalid date" << std::endl;
		return false;
	}
	int originalDay = timeStruct.tm_mday;

	std::mktime(&timeStruct);
	if (timeStruct.tm_mday != originalDay) {
		std::cerr << "Error: invalid date" << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: Could not open database.");
	std::string line;
	std::getline(file, line); // Skip first line
	while (std::getline(file, line)) {
		size_t sep = line.find(',');
		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 1);
		double value = toDouble(valueStr);
		_prices[date] = value;
	}
}

double BitcoinExchange::getRate(const std::string &date) const {
	std::map<std::string, double>::const_iterator it = _prices.lower_bound(date);
	if (it == _prices.end()) {
		--it;
	}
	else if (it->first != date && it != _prices.begin()) {
		--it;
	}
	return it->second;
}

void BitcoinExchange::processInput(const std::string &filename) const {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: Could not open input file.");
	std::string line;
	std::getline(file, line); // Skip first line
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		size_t sep = line.find('|');
		if (sep == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, sep));
		std::string valueStr = trim(line.substr(sep + 1));
		std::istringstream iss(valueStr);
		double value;
		if (!(iss >> value)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		double rate = getRate(date);
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
}

void BitcoinExchange::print() const { // DEBUG
	for (std::map<std::string, double>::const_iterator it = _prices.begin(); it != _prices.end(); it++) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
}
