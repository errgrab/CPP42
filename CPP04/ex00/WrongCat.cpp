#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat) : WrongAnimal(wrongcat) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongcat) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &wrongcat)
        type = wrongcat.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}
