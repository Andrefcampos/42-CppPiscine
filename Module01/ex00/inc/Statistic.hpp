#pragma once

class Statistic {
    private:
        int level;
        int exp;
    public:
        Statistic();
        ~Statistic();

        int getLevel() const;
        int getExp() const;

        void setLevel(const int &level);
        void setExp(const int &exp);
};