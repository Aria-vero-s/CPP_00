#include "Phonebook.hpp"

bool checkNumber(std::string &input) {
    size_t i = 0;
    char c;
    while (input.empty()) {
        std::cout << RED << "Error: input can't be blank. Please try again:" << std::endl << RESET;
        if (!std::getline(std::cin, input)) {
            std::cout << RED << "EOF error (maybe ctrl-D)" << std::endl << RESET;
            return (false);
        }
    }
    while (i < input.length()) {
        c = input[i];
        if (c < '0' || c > '9')
            return (false);
        i++;
    }
    return (true);
}

bool promptLine(std::string &input) {
    if (!std::getline(std::cin, input)) {
        std::cout << RED << "EOF error (maybe ctrl-D)" << std::endl << RESET;
        return (false);
    }
    while (input.empty()) {
        std::cout << RED << "Error: input can't be blank. Please try again:" << std::endl << RESET;
        if (!std::getline(std::cin, input)) {
            std::cout << RED << "EOF error (maybe ctrl-D)" << std::endl << RESET;
            return (false);
        }
    }
    return (true);
}

bool isNumber(const std::string &input) {
    size_t i = 0;
    while (i < input.length()) {
        if (input[i] < '0' || input[i] > '9')
            return false;
        i++;
    }
    return true;
}

bool promptNumber(std::string &input) {
    if (!std::getline(std::cin, input)) {
        std::cout << RED << "EOF error (maybe ctrl-D)" << std::endl << RESET;
        return (false);
    }
    while (input.empty()) {
        std::cout << RED << "Error: input can't be blank. Please try again:" << std::endl << RESET;
        if (!std::getline(std::cin, input)) {
            std::cout << RED << "EOF error (maybe ctrl-D)" << std::endl << RESET;
            return (false);
        }
    }
    while (!checkNumber(input)) {
        std::cout << RED << "Error: must be digits." << RESET << std::endl;
        if (!std::getline(std::cin, input)) {
            std::cout << RED << "EOF error (maybe ctrl-D)" << std::endl << RESET;
            return (false);
        }
    }
    return (true);
}

std::string formatField(const std::string& input) {
    if (input.length() > 10)
        return input.substr(0, 9) + ".";
    else
        return input;
}

int addNewContact(Phonebook &phonebook) {
    std::string temp;
    Contact c;

    std::cout << MAGENTA << "FIRST NAME: " << std::endl << RESET;
    if (!promptLine(temp))
        return 1;
    c.setFname(temp);
    
    std::cout << MAGENTA << "LAST NAME: " << std::endl << RESET;
    if (!promptLine(temp))
        return 1;
    c.setLname(temp);
    
    std::cout << MAGENTA << "NICKNAME: " << std::endl << RESET;
    if (!promptLine(temp))
        return 1;
    c.setNickname(temp);
    
    std::cout << MAGENTA << "PHONE NUMBER: " << std::endl << RESET;
    if (!promptNumber(temp))
        return 1;
    c.setNumber(temp);
    
    std::cout << MAGENTA << "DARKEST SECRET: " << std::endl << RESET;
    if (!promptLine(temp))
        return 1;
    c.setSecret(temp);
    
    phonebook.addContact(c);
    return (0);
}

int    SecondPrompt(Phonebook &phonebook) {
    std::string input;
    int index = 0;
    std::cout << MAGENTA << "→ SELECT A CONTACT" << std::endl << RESET;
    std::cout << MAGENTA << "→ OR TYPE MENU TO GO BACK" << std::endl << RESET;
    while (true) {
        if (!promptLine(input))
            return 1;
        if (input == "MENU")
            return (0);
        if (!isNumber(input)) {
            std::cout << RED << "Invalid input. Please enter MENU or a number." << RESET << std::endl;
            continue;
        }
        index = std::atoi(input.c_str());
        if (index < 0 || index >= phonebook.getQuantity()) {
            std::cout << RED << "Index out of range. Please enter 0 to " << RESET << phonebook.getQuantity() - 1 << "." << std::endl;
            continue;
        }
        break;
    }
    std::cout << MAGENTA << "CONTACT [" << index << "]'S FULL DETAILS:" << std::endl << RESET;
    std::cout << std::setw(20) << "Index" << "|" << index << std::endl;
    const Contact &contact = phonebook.getContact(index);
    std::cout << std::setw(20) << "First Name" << "|" << contact.getFname() << std::endl;
    std::cout << std::setw(20) << "Last Name" << "|" << contact.getLname() << std::endl;
    std::cout << std::setw(20) << "Nickname" << "|" << contact.getNickname() << std::endl;
    std::cout << std::setw(20) << "Number" << "|" << contact.getNumber() << std::endl;
    std::cout << std::setw(20) << "Darkest Secret" << "|" << contact.getSecret() << std::endl;
    return (0);
}

void    PrintSearchResults(Phonebook &phonebook) {
    int i = 0;
    if (phonebook.getQuantity() == 0)
        std::cout << MAGENTA << std::endl << "NO CONTACTS YET" << std::endl << RESET;
    else {
        std::cout << MAGENTA << std::endl << "SEARCH CONTACTS :" << std::endl << RESET;
        std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
        std::cout << "----------|----------|----------|----------|" << std::endl;
        while(i < phonebook.getQuantity()) {
            const Contact &contact = phonebook.getContact(i);
            std::cout << std::setw(10) << i << "|";
            std::cout << std::setw(10) << formatField(contact.getFname()) << "|";
            std::cout << std::setw(10) << formatField(contact.getLname()) << "|";
            std::cout << std::setw(10) << formatField(contact.getNickname()) << "|" << std::endl;
            std::cout << "----------|----------|----------|----------|" << std::endl;
            i++;
        }
        SecondPrompt(phonebook);
    }
}

int    ExitPhonebook() {
    std::cout << MAGENTA << "EXIT PHONEBOOK " << std::endl;
    std::cout << RED << "All contacts erased!" << std::endl << RESET;
    return (0);
}

int main() {
    Phonebook phonebook;
    std::string input;
    int exit = 1;
    std::cout << CYAN << BOLD << "╔══════════════════════╗" << std::endl;
    std::cout << CYAN << BOLD << "║ MY AWESOME PHONEBOOK ║" << std::endl;
    std::cout << CYAN << BOLD << "╚══════════════════════╝" << RESET;
    while (exit) {
        std::cout << CYAN << std::endl << "Please enter ADD, SEARCH or EXIT" << std::endl << RESET;
        if (!promptLine(input))
            return (1);
        if (input == "ADD")
            addNewContact(phonebook);
        else if (input == "SEARCH")
            PrintSearchResults(phonebook);
        else if (input == "EXIT")
            exit = ExitPhonebook();
        else
            std::cout << RED << "Please select a valid option." << RESET << std::endl;
    }
    return (0);
}