#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
    private :
        std::string name;
    public :
        Zombie(std::string n);
        ~Zombie();
        void announce(void);
};

Zombie* newZombie(std::string n);
void randomChump(std::string n);

#endif