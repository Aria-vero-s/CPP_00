#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    int i;
    Zombie *ptr;
    
    i = 0;
    ptr = new Zombie[N];
    while (i < N)
    {
        ptr[i].setName(name);
        i++;
    }
    return (ptr);
}