#pragma once

#include <string>

class ScalarConverter {

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter&);

public:
	static void convert(const std::string &value);

};
