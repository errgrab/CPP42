#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av) {
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	else if (ac > 1) {
		for (int i = 1; i < ac; ++i)
		{
			std::string str = av[i];
			for (std::string::iterator it = str.begin(); it != str.end(); it++)
				*it = static_cast<char>(std::toupper(static_cast<unsigned char>(*it)));
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}
