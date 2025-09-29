#include "Zombie.hpp"

Zombie::Zombie(std::string n) {
    name = n;
    announce();
};
Zombie::~Zombie() {
    std::cout << "Destroyed: " << name << std::endl;
}
void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
