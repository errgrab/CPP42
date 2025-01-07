#pragma once

#include <string>

class Animal {
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    virtual void makeSound() const;
    const std::string& getType() const;
};
