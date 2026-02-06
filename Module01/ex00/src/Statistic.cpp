#include "Statistic.hpp"
#include <iostream>

Statistic::Statistic() : level(0), exp(0) {
    std::cout << "Statistic default constructor called" << std::endl;
}

Statistic::~Statistic() {
    std::cout << "Statistic destructor called" << std::endl;
}

int Statistic::getLevel() const {
    return this->level;
}

int Statistic::getExp() const {
    return this->exp;
}

void Statistic::setLevel(const int &level) {
    this->level = level;
}

void Statistic::setExp(const int &exp) {
    this->exp = exp;
}