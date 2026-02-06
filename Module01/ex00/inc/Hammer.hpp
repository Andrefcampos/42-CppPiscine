#pragma once
#include "Tool.hpp"

class Hammer : public Tool {
    private:
        int numberOfUses;
        
    public:
        Hammer();
        ~Hammer();

        void use();
};