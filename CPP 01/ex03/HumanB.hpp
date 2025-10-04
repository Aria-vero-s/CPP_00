#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon      *weapon;
    public:
        HumanB(std::string n);
        void    setWeapon(Weapon &w);
        void    attack();
};

#endif