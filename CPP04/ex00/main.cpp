#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong = new WrongCat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrong->getType() << " " << std::endl;

    meta->makeSound();
    i->makeSound();
    j->makeSound();
    wrong->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrong;
    return 0;
}
