#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "";
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& brain) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = brain.getIdea(i);
    }
}

Brain& Brain::operator=(const Brain& brain) {
    for (int i = 0; i < 100; i++) {
        ideas[i] = brain.getIdea(i);
    }
    return *this;
}

std::string Brain::getIdea(int index) const {
    return ideas[index];
}

void Brain::setIdea(int index, std::string idea) {
    ideas[index] = idea;
}
