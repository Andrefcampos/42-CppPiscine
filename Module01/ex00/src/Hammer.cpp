#include "Hammer.hpp"
#include <iostream>

Hammer::Hammer() : numberOfUses(0) {
    std::cout << "Hammer default constructor called" << std::endl;
}
Hammer::~Hammer() {
    std::cout << "Hammer destructor called" << std::endl;
}

void Hammer::use() {
    this->numberOfUses++;
    std::cout << "Hammer used. Total uses: " << this->numberOfUses << std::endl;
}