#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD      "\033[1m"

#define MAX 8

class Contact {
    public:
        std::string fname;
        std::string lname;
        std::string surname;
        std::string number;
        std::string secret;
    Contact() {
        fname = "undefined";
        lname = "undefined";
        surname = "undefined";
        number = "undefined";
        secret = "undefined";
    }
};

class Phonebook {
    public:
        int quantity;
        Contact arr[MAX + 1];
    Phonebook() {
        quantity = 0;
    }
};

bool prompt_line(std::string &input) {
    if (!std::getline(std::cin, input)) {
        std::cout << "EOF error (maybe ctrl-D)" << std::endl;
        return (false);
    }
    return (true);
}

std::string formatField(const std::string& input) {
    if (input.length() > 10)
        return input.substr(0, 9) + ".";
    else
        return input;
}

void    CheckPhonebookLimit(Phonebook &phonebook) {
    int i = 7;
    if (phonebook.quantity == 9)
    {
        while (i > 0)
        {
            phonebook.arr[i] = phonebook.arr[i - 1];
            i--;
        }
        phonebook.arr[0] = phonebook.arr[8];
        phonebook.quantity = 8;
    }
}

int    AddContact(Phonebook &phonebook, Contact &contact) {
    std::cout << MAGENTA << "ENTRER FIRST NAME :" << std::endl << RESET;
    if (!prompt_line(phonebook.arr[phonebook.quantity].fname))
        return (1);
    std::cout << MAGENTA "ENTRER LAST NAME :" << std::endl << RESET;
    if (!prompt_line(phonebook.arr[phonebook.quantity].lname))
        return (1);
    std::cout << MAGENTA "ENTRER SURNAME :" << std::endl << RESET;
    if (!prompt_line(phonebook.arr[phonebook.quantity].surname))
        return (1);
    std::cout << MAGENTA "ENTRER PHONENUMBER :" << std::endl << RESET;
    if (!prompt_line(phonebook.arr[phonebook.quantity].number))
        return (1);
    std::cout << MAGENTA "ENTRER SECRET :" << std::endl << RESET;
    if (!prompt_line(phonebook.arr[phonebook.quantity].secret))
        return (1);
    phonebook.quantity++;
    CheckPhonebookLimit(phonebook);
    return (0);
}

int    SecondPrompt(Phonebook &phonebook) {
    int i = 0;
    std::string input;
    int index = 0;
    std::cout << MAGENTA << "SELECT A CONTACT" << std::endl << RESET;
        while (true) {
        if (!prompt_line(input))
            return 1;
        if (input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        index = std::stoi(input);
        if (index < 0 || index >= phonebook.quantity) {
            std::cout << "Index out of range. Please enter 0 to " << phonebook.quantity - 1 << "." << std::endl;
            continue;
        }
        break;
    }
    std::cout << MAGENTA << "CONTACT [" << index << "]'S FULL DETAILS:" << std::endl << RESET;
    std::cout << std::setw(10) << "Index" << "|" << index << std::endl;
    std::cout << std::setw(10) << "First Name" << "|" << phonebook.arr[index].fname << std::endl;
    std::cout << std::setw(10) << "Last Name" << "|" << phonebook.arr[index].lname << std::endl;
    std::cout << std::setw(10) << "Surname" << "|" << phonebook.arr[index].surname << std::endl;
    std::cout << std::setw(10) << "Number" << "|" << phonebook.arr[index].number << std::endl;
    std::cout << std::setw(10) << "Secret" << "|" << phonebook.arr[index].secret << std::endl;
    return (0);
}

void    PrintSearchResults(Phonebook &phonebook) {
    int i = 0;
    std::cout << MAGENTA << std::endl << "SEARCH CONTACTS :" << std::endl << RESET;
    std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Surname" << "|" << std::endl;
    std::cout << "----------|----------|----------|----------|" << std::endl;
    while(i < phonebook.quantity) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << formatField(phonebook.arr[i].fname) << "|";
        std::cout << std::setw(10) << formatField(phonebook.arr[i].lname) << "|";
        std::cout << std::setw(10) << formatField(phonebook.arr[i].surname) << "|" << std::endl;
        std::cout << "----------|----------|----------|----------|" << std::endl;
        i++;
    }
    SecondPrompt(phonebook);
}

int    ExitPhonebook(Phonebook &phonebook) {
    std::cout << MAGENTA << "EXIT PHONEBOOK " << RED "Your contacts have been erased!" << std::endl << RESET;
    return (0);
}

int main() {
    Phonebook phonebook;
    Contact contact;
    std::string input;
    int exit = 1;
    std::cout << CYAN << BOLD << "╔══════════════════════╗" << std::endl;
    std::cout << CYAN << BOLD << "║ MY AWESOME PHONEBOOK ║" << std::endl;
    std::cout << CYAN << BOLD << "╚══════════════════════╝" << RESET;
    while (exit) {
        std::cout << CYAN << std::endl << "Please enter ADD, SEARCH or EXIT" << std::endl << RESET;
        if (!prompt_line(input))
            return (1);
        if (input == "ADD")
            AddContact(phonebook, contact);
        else if (input == "SEARCH")
            PrintSearchResults(phonebook);
        else if (input == "EXIT")
            exit = ExitPhonebook(phonebook);
        else
            std::cout << "Please select a valid option." << std::endl << std::endl;
    }
    return (0);
}