#pragma once

#include <string>

class Converter {

private:
	Converter() {}
	Converter(const Converter&) {}
	~Converter() {}
	Converter &operator=(const Converter&) {return *this;}

	static int toInt(const std::string &value);
	static double toDouble(const std::string &value);
	
	static void showChar(const std::string &value);
	static void showInt(const std::string &value);
	static void showFloat(const std::string &value);
	static void showDouble(const std::string &value);

public:
	static void show(const std::string &value);

};
