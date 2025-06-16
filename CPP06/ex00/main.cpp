#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cctype>

class Converter {
private:
	Converter();
	Converter(const Converter &other);
	~Converter();
	Converter &operator=(const Converter &other);

public:
	static void show(const std::string &value) {
		// CHAR
		
		std::istringstream iss(value);
		long tmp;
		if (!(iss >> tmp) || !iss.eof() ||
				tmp < std::numeric_limits<char>::min() ||
				tmp > std::numeric_limits<char>::max()) {
			std::cout << "char: impossible" << std::endl;
		} else {
			char charValue = static_cast<char>(tmp);
			if (std::isprint(charValue)) {
				std::cout << "char: '" << charValue << "'" << std::endl;
			} else {
				std::cout << "char: Non displayable" << std::endl;
			}
		}
		/*
		try {
			char charValue = static_cast<char>(std::stoi(value));
			if (std::isprint(charValue)) {
				std::cout << "char: '" << charValue << "'" << std::endl;
			} else {
				std::cout << "char: Non displayable" << std::endl;
			}
		} catch (const std::exception &e) {
			std::cout << "char: impossible" << std::endl;
		}

		try {
			int intValue = std::stoi(value);
			std::cout << "int: " << intValue << std::endl;
		} catch (const std::exception &e) {
			std::cout << "int: impossible" << std::endl;
		}

		try {
			float floatValue = std::stof(value);
			std::cout << "float: " << floatValue << "f" << std::endl;
		} catch (const std::exception &e) {
			std::cout << "float: impossible" << std::endl;
		}

		try {
			double doubleValue = std::stod(value);
			std::cout << "double: " << doubleValue << std::endl;
		} catch (const std::exception &e) {
			std::cout << "double: impossible" << std::endl;
		}*/
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
