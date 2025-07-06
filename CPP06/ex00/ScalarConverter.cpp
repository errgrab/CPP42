#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) {return *this;}

int ScalarConverter::toInt(const std::string &value) {
	double d = toDouble(value);
	bool inRange = (d >= std::numeric_limits<int>::min()
				 && d <= std::numeric_limits<int>::max());
	if (isnan(d) || isinf(d) || !inRange)
		throw std::exception();
	return static_cast<int>(d);
}

double ScalarConverter::toDouble(const std::string &value) {
	if (value.size() == 0)
		throw std::exception();
	char* endPtr;
	double d = strtod(value.c_str(), &endPtr);
	const char* str = value.c_str();
	size_t len = value.size();
	bool fullyParsed = (endPtr == str + len);
	bool endsWithF = (len > 0 && value[len - 1] == 'f');
	bool parsedExceptLastF = (endsWithF && endPtr == str + len - 1);
	if (len == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return static_cast<double>(str[0]);
	if (!fullyParsed && !parsedExceptLastF)
		throw std::exception();
	return d;
}

void ScalarConverter::showChar(const std::string &value) {
	try {
		double d = toDouble(value);
		if (d < std::numeric_limits<char>::min()
			|| d > std::numeric_limits<char>::max()) {
			std::cout << "char: impossible" << std::endl;
		} else {
			char c = static_cast<char>(d);
			std::cout << "char: ";
			std::cout << (std::isprint(c) ? "'" + std::string(1, c) + "'" :
							"Non displayable") << std::endl;
		}
	} catch (...) {
		std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::showInt(const std::string &value) {
	try {
		int i = toInt(value);
		std::cout << "int: " << i << std::endl;
	} catch (...) {
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::showFloat(const std::string &value) {
	try {
		float f = static_cast<float>(toDouble(value));
		if (isnan(f)) {
			std::cout << "float: nanf" << std::endl;
		} else if (isinf(f)) {
			std::cout << "float: " << (f < 0 ? "-inff" : "inff") << std::endl;
		} else if (f == floor(f)) {
			std::cout << "float: " << f << ".0f" << std::endl;
		} else {
			std::cout << "float: " << f << "f" << std::endl;
		}
	} catch (...) {
		std::cout << "float: impossible" << std::endl;
	}
}

void ScalarConverter::showDouble(const std::string &value) {
	try {
		double d = toDouble(value);
		if (isnan(d)) {
			std::cout << "double: nan" << std::endl;
		} else if (isinf(d)) {
			std::cout << "double: " << (d < 0 ? "-inf" : "inf") << std::endl;
		} else if (d == floor(d)) {
			std::cout << "double: " << d << ".0" << std::endl;
		} else {
			std::cout << "double: " << d << std::endl;
		}
	} catch (...) {
		std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &value) {
	showChar(value);
	showInt(value);
	showFloat(value);
	showDouble(value);
}
