#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal) : type(wronganimal.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganimal) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &wronganimal)
        type = wronganimal.type;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "Wrong! Wrong!" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return type;
}
