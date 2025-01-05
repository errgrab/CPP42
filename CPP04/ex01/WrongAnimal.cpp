#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal) : _type(wronganimal._type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganimal) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &wronganimal)
        _type = wronganimal._type;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "Wrong! Wrong!" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return _type;
}