#pragma once

#include <iostream>
#include <string>

#include "Brain.hpp"

class Animal {
protected:
    std::string _type;
    Brain* _brain;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    virtual void makeSound() const;
    const std::string& getType() const;
    Brain* getBrain() const;
};