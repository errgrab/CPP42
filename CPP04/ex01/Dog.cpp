#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &dog)
        type = dog.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}
