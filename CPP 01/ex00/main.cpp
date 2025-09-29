#include "Zombie.hpp"

int main() {
    Zombie *ptr;

    ptr = newZombie("Foo");
    randomChump("Bob");
    delete ptr;
}