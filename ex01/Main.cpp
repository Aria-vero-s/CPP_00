#include <iostream>
#include <string>
#include <iomanip>

#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

#define MAX 8

class Contact {
    public:
        std::string fname;
        std::string lname;
        std::string surname;
        std::string number;
        std::string secret;
 Contact() {
        fname = "defined";
        lname = "defined";
        surname = "undefined";
        number = "undefined";
        secret = "ndefined";
    }
};

class Phonebook {
    public:
        int quantity;
        Contact arr[MAX];
    Phonebook() {
        quantity = 0;
    }
};

std::string formatField(const std::string& input) {
    if (input.length() > 10)
        return input.substr(0, 9) + ".";
    else
        return input;
}

void    AddContact(Phonebook &phonebook, Contact &contact) {
    std::cout << RED << "ENTRER FIRST NAME :" << std::endl << RESET;
    std::cin >> phonebook.arr[phonebook.quantity].fname;
    std::cout << RED "ENTRER LAST NAME :" << std::endl << RESET;
    std::cin >> phonebook.arr[phonebook.quantity].lname;
    std::cout << RED "ENTRER SURNAME :" << std::endl << RESET;
    std::cin >> phonebook.arr[phonebook.quantity].surname;
    std::cout << RED "ENTRER PHONENUMBER :" << std::endl << RESET;
    std::cin >> phonebook.arr[phonebook.quantity].number;
    std::cout << RED "ENTRER SECRET :" << std::endl << RESET;
    std::cin >> phonebook.arr[phonebook.quantity].secret;
    phonebook.quantity++;
}

void    PrintContact(Phonebook &phonebook) {
    int i = 0;
    std::cout << "SEARCH CONTACTS :" << std::endl;
    std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Surname" << "|" << std::setw(10) << "Number" << "|" << std::setw(10) << "Secret" << "|" << std::endl;
    std::cout << "----------|----------|----------|----------|----------|----------|" << std::endl;
    while(i < phonebook.quantity) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << formatField(phonebook.arr[i].fname) << "|";
        std::cout << std::setw(10) << formatField(phonebook.arr[i].lname) << "|";
        std::cout << std::setw(10) << formatField(phonebook.arr[i].surname) << "|";
        std::cout << std::setw(10) << formatField(phonebook.arr[i].number) << "|";
        std::cout << std::setw(10) << formatField(phonebook.arr[i].secret) << "|" << std::endl;
        std::cout << "----------|----------|----------|----------|----------|----------|" << std::endl;
        i++;
    }
}

int    ExitPhonebook(Phonebook &phonebook) {
    std::cout << "Exit Phonebook. Your contacts have been erased." << std::endl;
    return (0);
}

int main() {
    Phonebook phonebook;
    Contact contact;
    std::string input;
    int exit = 1;
    std::cout << CYAN << "--------------------" << std::endl;
    std::cout << "MY AWESOME PHONEBOOK" << std::endl;
    std::cout << "--------------------" << std::endl << RESET;
    while (exit) {
        std::cout << CYAN << "Please enter ADD, SEARCH or EXIT" << std::endl << RESET;
        std::cin >> input;
        if (input == "ADD")
            AddContact(phonebook, contact);
        else if (input == "SEARCH")
            PrintContact(phonebook);
        else if (input == "EXIT")
            exit = ExitPhonebook(phonebook);
        else
            std::cout << "Please select a valid option." << std::endl << std::endl;
    }
}