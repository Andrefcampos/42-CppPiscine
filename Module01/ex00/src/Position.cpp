#include "Position.hpp"
#include <iostream>

Position::Position() : x(0), y(0), z(0) {
    std::cout << "Position default constructor called" << std::endl;
}

Position::~Position() {
    std::cout << "Position destructor called" << std::endl;
}

int Position::getX() const {
    return this->x;
}

int Position::getY() const {
    return this->y;
}

int Position::getZ() const {
    return this->z;
}

void Position::setX(const int &x) {
    this->x = x;
}

void Position::setY(const int &y) {
    this->y = y;
}

void Position::setZ(const int &z) {
    this->z = z;
}