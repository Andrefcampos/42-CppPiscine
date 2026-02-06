#pragma once

class Position
{
    private:
        int x;
        int y;
        int z;

    public:
        Position();
        ~Position();

        int getX() const;
        int getY() const;
        int getZ() const;

        void setX(const int &x);
        void setY(const int &y);
        void setZ(const int &z);
};
