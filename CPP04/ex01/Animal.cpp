#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal"), brain(new Brain()) {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
    delete brain;
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& animal) : type(animal.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &animal)
        type = animal.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound!" << std::endl;
}

const std::string& Animal::getType() const {
    return type;
}

Brain* Animal::getBrain() const {
    return brain;
}
