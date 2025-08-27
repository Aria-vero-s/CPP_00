#include "Phonebook.hpp"
#include <iostream>
#include <string>

#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

int main()
{
    Phonebook obj;
    std::string option;

    while (1)
    {
        std::cout << CYAN << "Please enter ADD, SEARCH or EXIT" << std::endl << RESET;
        if (!std::getline(std::cin, option)) {
            std::cout << std::endl << "Goodbye (EOF)." << std::endl;
            return 0;
        }
        if (option == "ADD")
            obj.AddContact();
        else if (option == "SEARCH")
            obj.SearchContact();
        else if (option == "EXIT")
            return (obj.Exit());
        else
            std::cout << RED << "Error: please choose a valid option." << std::endl << RESET;
        std::cout << std::endl;
    }
    return 0;
}
