#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

Phonebook::Phonebook()
: _count(0), _next(0) {}

Phonebook::~Phonebook() {}

std::string Phonebook::formatField(const std::string &s) {
    if (s.length() <= 10)
    {
        std::ostringstream oss;
        oss << std::setw(10) << s;
        return oss.str();
    }
    return s.substr(0, 9) + ".";
}

void Phonebook::AddContact() {
    std::cout << "ADD A NEW CONTACT :" << std::endl;
    // reuse Contact's interactive setter
    _contacts[_next].SetContactInteractive();

    // update counters
    if (_count < _maxContacts)
        _count++;
    _next = (_next + 1) % _maxContacts;

    std::cout << "Contact stored.\n";
}

void Phonebook::SearchContact() {
    if (_count == 0) {
        std::cout << "No contacts in the phonebook.\n";
        return;
    }

    // header
    std::cout << std::setw(10) << "Index" << "|" 
              << std::setw(10) << "First Name" << "|" 
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Surname" << std::endl;
    // separator
    std::cout << "----------|----------|----------|----------" << std::endl;

    // print contacts
    for (int i = 0; i < _count; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << formatField(_contacts[i].GetFirstName()) << "|"
                  << formatField(_contacts[i].GetLastName()) << "|"
                  << formatField(_contacts[i].GetSurname()) << std::endl;
    }

    // ask for index
    std::string line;
    std::cout << "Enter index to display (or press ENTER to cancel): ";
    std::getline(std::cin, line);
    if (line.empty()) {
        std::cout << "Cancelled.\n";
        return;
    }

    // validate numeric index
    std::istringstream iss(line);
    int idx;
    if (!(iss >> idx) || idx < 0 || idx >= _count) {
        std::cout << "Invalid index.\n";
        return;
    }

    // display full contact
    std::cout << "----- Contact " << idx << " -----\n";
    _contacts[idx].DisplayFull();
}

int Phonebook::Exit() {
    std::cout << "Exit program\n";
    return 0;
}
