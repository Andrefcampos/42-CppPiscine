#include "Worker.hpp"
#include <iostream>

Worker::Worker() {
    std::cout << "Worker default constructor called" << std::endl;
}

Worker::~Worker() {
    std::cout << "Worker destructor called" << std::endl;
}

Position Worker::getPosition() const {
    return this->coordonnee;
}

Statistic Worker::getStatistic() const {
    return this->stat;
}

void Worker::setPosition(const Position &pos) {
    this->coordonnee = pos;
}

void Worker::setStatistic(const Statistic &stat) {
    this->stat = stat;
}

void Worker::takeTool(Tool* tool) {
    this->tools.push_back(tool);
}

void Worker::removeTool(Tool* tool) {
    for (size_t i = 0; i < tools.size(); i++) {
        if (tools[i] == tool) {
            tools.erase(tools.begin() + i);
            return;
        }
    }
}

void Worker::work() {
    std::cout << "Worker is working..." << std::endl;
    
    for (size_t i = 0; i < tools.size(); i++) {
        tools[i]->use();
    }
}