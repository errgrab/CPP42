#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cctype>
#include <cstdlib>  // for strtod

class Converter {
private:
	Converter() {}
	Converter(const Converter&) {(void)this;}
	~Converter() {}
	Converter &operator=(const Converter&) {(void)this; return *this;}

public:
	static void show(const std::string &value) {
		// Handle single non-digit character case first
		if (value.size() == 1 && !std::isdigit(static_cast<unsigned char>(value[0]))) {
			char c = value[0];
			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << std::endl;
			return;
		}

		try {
			char* endPtr;
			double d = strtod(value.c_str(), &endPtr);
			if (endPtr != value.c_str() + value.size() || std::isnan(d) || std::isinf(d)) {
				throw std::exception();
			}
			if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
				std::cout << "char: impossible" << std::endl;
			} else {
				char c = static_cast<char>(d);
				std::cout << "char: " << (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable") << std::endl;
			}
		} catch (...) {
			std::cout << "char: impossible" << std::endl;
		}

		try {
			char* endPtr;
			double d = strtod(value.c_str(), &endPtr);
			if (endPtr != value.c_str() + value.size() || std::isnan(d) || std::isinf(d) ||
				d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
				throw std::exception();
			}
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		} catch (...) {
			std::cout << "int: impossible" << std::endl;
		}

		try {
			char* endPtr;
			double d = strtod(value.c_str(), &endPtr);
			if (endPtr != value.c_str() + value.size() && !(value.size() > 0 && value[value.size()-1] == 'f' && endPtr == value.c_str() + value.size() - 1)) {
				throw std::exception();
			}
			float f = static_cast<float>(d);
			std::cout << "float: " << f;
			if (std::isnan(f) || std::isinf(f) || f == std::floor(f)) {
				std::cout << ".0f" << std::endl;
			} else {
				std::cout << "f" << std::endl;
			}
		} catch (...) {
			std::cout << "float: impossible" << std::endl;
		}

		try {
			char* endPtr;
			double d = strtod(value.c_str(), &endPtr);
			if (endPtr != value.c_str() + value.size() && !(value.size() > 0 && value[value.size()-1] == 'f' && endPtr == value.c_str() + value.size() - 1)) {
				throw std::exception();
			}
			std::cout << "double: " << d;
			if (std::isnan(d) || std::isinf(d) || d == std::floor(d)) {
				std::cout << ".0" << std::endl;
			} else {
				std::cout << std::endl;
			}
		} catch (...) {
			std::cout << "double: impossible" << std::endl;
		}
	}
};

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <value>" << std::endl;
		return 1;
	}

	Converter::show(av[1]);

	return 0;
}
