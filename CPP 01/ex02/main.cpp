#include <iostream>
#include <string>

int main() {
    std::string brain;
    std::string *stringPTR;
    std::string &stringREF = brain;

    brain = "HI THIS IS BRAIN";
    stringPTR = &brain;
    std::cout << "The memory address of the string variable: " << &brain << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "The value of the string variable: " << brain << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}