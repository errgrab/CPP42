#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <cmath>

class Converter {
private:
	Converter() {}
	Converter(const Converter&) {(void)this;}
	~Converter() {}
	Converter &operator=(const Converter&) {(void)this; return *this;}

	static int toInt(const std::string &value) {
		double d = toDouble(value);

		bool inRange = (d >= std::numeric_limits<int>::min()
					 && d <= std::numeric_limits<int>::max());

		if (isnan(d) || isinf(d) || !inRange)
			throw std::exception();

		return static_cast<int>(d);
	}

	static double toDouble(const std::string &value) {
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

	static void showChar(const std::string &value) {
		try {
			double d = toDouble(value);
			if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
				std::cout << "char: impossible" << std::endl;
			} else {
				char c = static_cast<char>(d);
				std::cout << "char: " << (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable") << std::endl;
			}
		} catch (...) {
			std::cout << "char: impossible" << std::endl;
		}
	}

	static void showInt(const std::string &value) {
		try {
			int i = toInt(value);
			std::cout << "int: " << i << std::endl;
		} catch (...) {
			std::cout << "int: impossible" << std::endl;
		}
	}

	static void showFloat(const std::string &value) {
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

	static void showDouble(const std::string &value) {
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

public:
	static void show(const std::string &value) {
		showChar(value);
		showInt(value);
		showFloat(value);
		showDouble(value);
	}
};

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <value>" << std::endl;
		return 1;
	}

	Converter::show(av[1]);

	return 0;
}
