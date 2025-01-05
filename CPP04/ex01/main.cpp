#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const int numAnimals = 50;
    for (int i = 0; i < numAnimals; i++) {
        const Animal* animal;
        if (i % 2 == 0)
            animal = new Cat();
        else
            animal = new Dog();
        animal->makeSound();
        delete animal;
    }
    return 0;
}