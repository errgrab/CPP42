#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string name;
public:
    Zombie();
    ~Zombie();
    void setName(std::string name);
    void announce() const;
};

Zombie* zombieHorde(int N, std::string name);

#endif
