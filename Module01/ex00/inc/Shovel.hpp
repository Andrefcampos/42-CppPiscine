#pragma once
#include "Tool.hpp"

class Shovel : public Tool {
    private:
        int numberOfUses;
        
    public:
        Shovel();
        ~Shovel();

        void use();
};