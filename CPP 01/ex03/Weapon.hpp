#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string t);
        void    setType(std::string t);
        std::string  getType();
};

#endif