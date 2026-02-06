#pragma once

class Tool {
    public:
        virtual ~Tool();
        virtual void use() = 0;
};