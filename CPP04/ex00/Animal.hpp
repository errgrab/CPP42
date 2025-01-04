#pragma once

#include <iostream>
#include <string>

class Animal {
protected:
    std::string _type;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    virtual void makeSound() const;
    const std::string& getType() const;
};