#include <iostream>

std::string toUpper(const std::string& str) {
	std::string upperStr = str;
	for (char *p = &upperStr[0]; *p; ++p)
		*p = std::toupper(*p);
	return upperStr;
}

int main(int ac, char **av) {
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	else if (ac > 1) {
		for (int i = 1; i < ac; ++i)
			std::cout << toUpper(av[i]);
		std::cout << std::endl;
	}
	return (0);
}
