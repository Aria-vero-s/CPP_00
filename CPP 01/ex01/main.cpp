#include "Zombie.hpp"

int main() {
    int N;
    int i;
    Zombie *ptr;

    N = 3;
    i = 0;
    ptr = zombieHorde(N, "Foo");

    while (i < N) {
        ptr[i].announce();
        i++;
    }

    delete[] ptr;
    return (0);
}