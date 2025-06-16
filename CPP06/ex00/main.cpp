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
			double d = strtod(value.c_str(), NULL);
			int intValue = static_cast<int>(d);
			if (intValue < std::numeric_limits<char>::min() || intValue > std::numeric_limits<char>::max()) {
				std::cout << "char: impossible" << std::endl;
			} else {
				char c = static_cast<char>(intValue);
				if (std::isprint(c)) {
					std::cout << "char: '" << c << "'" << std::endl;
				} else {
					std::cout << "char: Non displayable" << std::endl;
				}
			}
		} catch (...) {
			std::cout << "char: impossible" << std::endl;
		}

		try {
			int intValue = std::stoi(value);
			std::cout << "int: " << intValue << std::endl;
		} catch (const std::exception &e) {
			std::cout << "int: impossible" << std::endl;
		}

		try {
			float floatValue = static_cast<float>(strtod(value.c_str(), NULL));
			std::cout << "float: " << floatValue << "f" << std::endl;
		} catch (const std::exception &e) {
			std::cout << "float: impossible" << std::endl;
		}

		try {
			double doubleValue = strtod(value.c_str(), NULL);
			std::cout << "double: " << doubleValue << std::endl;
		} catch (const std::exception &e) {
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
