#include "Zombie.hpp"

void    Zombie::announce() {
    std::cout << "Zombie: " << name << std::endl;
}
void    Zombie::setName(std::string n) {
    name = n;
}