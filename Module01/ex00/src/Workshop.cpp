#include "Workshop.hpp"
#include "Worker.hpp"
#include <iostream>

Workshop::Workshop() {
    std::cout << "Workshop default constructor called" << std::endl;
}

Workshop::~Workshop() {
    std::cout << "Workshop destructor called" << std::endl;
}

void Workshop::registerWorker(Worker* worker) {
    workers.push_back(worker);
    std::cout << "Worker registered at Workshop" << std::endl;
}

void Workshop::releaseWorker(Worker* worker) {
    for (size_t i = 0; i < workers.size(); i++) {
        if (workers[i] == worker) {
            workers.erase(workers.begin() + i);
            std::cout << "Worker released from Workshop" << std::endl;
            return;
        }
    }
}

void Workshop::executeWorkDay() {
    std::cout << "Workshop executing work day for all workers" << std::endl;
    for (size_t i = 0; i < workers.size(); i++) {
        workers[i]->work();
    }
}