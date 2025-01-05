#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& animal) : _type(animal._type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &animal)
        _type = animal._type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound!" << std::endl;
}

const std::string& Animal::getType() const {
    return _type;
}