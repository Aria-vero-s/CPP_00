#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon  &weapon;
    public:
        HumanA(std::string n, Weapon &w);
        void    attack();
};

#endif