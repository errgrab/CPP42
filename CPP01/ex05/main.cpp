#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "usage: " << av[0] << " [debug/info/warning/error]" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(av[1]);
    return 0;
}