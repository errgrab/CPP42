#include "Zombie.hpp"
#include <iostream>
#include <sstream>

int main(int ac, char **av) {
    int n = 5;
    std::string name = "Zombie";
    if (ac >= 2 && ac <= 3) {
        std::stringstream ss(av[1]);
        ss >> n;
        if (ss.fail()) {
            std::cerr << "Invalid input" << std::endl;
            return 1;
        }
    }
    if (ac == 3)
        name = av[2];
    Zombie *horde = zombieHorde(n, name);
    for (int i = 0; i < n; i++) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
