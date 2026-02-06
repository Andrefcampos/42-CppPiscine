#include <iostream>
#include "Tool.hpp"

Tool::~Tool() {
    std::cout << "Tool destructor called" << std::endl;
}