#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal();
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal& wronganimal);
    WrongAnimal& operator=(const WrongAnimal& wronganimal);
    void makeSound() const;
    const std::string& getType() const;
};