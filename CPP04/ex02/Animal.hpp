#pragma once

#include <string>
#include "Brain.hpp"

class Animal {
protected:
    std::string type;
    Brain* brain;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    virtual void makeSound() const = 0;
    const std::string& getType() const;
    Brain* getBrain() const;
};
