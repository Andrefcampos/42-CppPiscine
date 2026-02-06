#include "Shovel.hpp"
#include <iostream>

Shovel::Shovel() : numberOfUses(0) {
    std::cout << "Shovel default constructor called" << std::endl;
}
Shovel::~Shovel() {
    std::cout << "Shovel destructor called" << std::endl;
}

void Shovel::use() {
    this->numberOfUses++;
    std::cout << "Shovel used. Total uses: " << this->numberOfUses << std::endl;
}