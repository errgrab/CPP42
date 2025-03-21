#pragma once

#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string type);
    ~Weapon();
    const std::string &getType();
    void setType(std::string newType);
};