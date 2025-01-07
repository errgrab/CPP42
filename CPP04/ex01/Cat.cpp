#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &cat)
        type = cat.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
