#pragma once

#include <string>

class ScalarConverter {

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter&);

	static int toInt(const std::string &value);
	static double toDouble(const std::string &value);
	
	static void showChar(const std::string &value);
	static void showInt(const std::string &value);
	static void showFloat(const std::string &value);
	static void showDouble(const std::string &value);

public:
	static void convert(const std::string &value);

};
