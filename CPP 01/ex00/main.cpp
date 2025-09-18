#include <iostream>

class Zombie {
    private :
        std::string name;
        void announce(void) {
            std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }
    public :
        ~Zombie() {
            std::cout << name << std::endl;
        }
};

// This function creates a zombie, names it,
// and returns it so you can use it outside
// of the function scope
Zombie* newZombie( std::string name ) {
    std::cout << "test1" << std::endl;
    return (Zombie);
}

// This function creates a zombie, names it, and makes it announce itself.
void randomChump( std::string name ) {
    std::cout << "test2" << std::endl;
}

int main() {
    std::string name;
    std::cout << "Enter a name for a new Zombie:" << std::endl;
    std::getline(std::cin, name);
}