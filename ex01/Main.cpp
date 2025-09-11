#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

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

std::string formatField(const std::string& input) {
    if (input.length() > 10)
        return input.substr(0, 9) + ".";
    else
        return input;
}

void    AddContact(Phonebook &phonebook, Contact &contact) {
    int i = 7;
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

void    SecondPrompt(Phonebook &phonebook) {
    int i = 0;
    int input;
    std::cout << CYAN << "SELECT A CONTACT" << std::endl << RESET;
    while (!(std::cin >> input) || input >= phonebook.quantity) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again.";
    }
    std::cout << CYAN << "CONTACT [" << input << "]'S FULL DETAILS:" << std::endl << RESET;
    std::cout << std::setw(10) << "Index" << "|" << input << std::endl;
    std::cout << std::setw(10) << "First Name" << "|" << phonebook.arr[input].fname << std::endl;
    std::cout << std::setw(10) << "Last Name" << "|" << phonebook.arr[input].lname << std::endl;
    std::cout << std::setw(10) << "Surname" << "|" << phonebook.arr[input].surname << std::endl;
    std::cout << std::setw(10) << "Number" << "|" << phonebook.arr[input].number << std::endl;
    std::cout << std::setw(10) << "Secret" << "|" << phonebook.arr[input].secret << std::endl;
}

void    PrintSearchResults(Phonebook &phonebook) {
    int i = 0;
    std::cout << "SEARCH CONTACTS :" << std::endl;
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
            PrintSearchResults(phonebook);
        else if (input == "EXIT")
            exit = ExitPhonebook(phonebook);
        else
            std::cout << "Please select a valid option." << std::endl << std::endl;
    }
}