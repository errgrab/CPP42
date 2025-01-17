#include <string>
#include <sstream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        std::stringstream ss;
        ss << name << i;
        horde[i].setName(ss.str());
    }
    return horde;
}
