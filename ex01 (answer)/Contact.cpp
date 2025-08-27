#include "Contact.hpp"
#include <iostream>

Contact::Contact()
: _firstName(""), _lastName(""), _surname(""), _phone(""), _secret("") {}

Contact::Contact(const std::string &firstname,
                 const std::string &lastname,
                 const std::string &surname,
                 const std::string &phone,
                 const std::string &secret)
: _firstName(firstname), _lastName(lastname), _surname(surname), _phone(phone), _secret(secret) {}

Contact::~Contact() {}

void Contact::SetFirstName(const std::string &s) { _firstName = s; }
void Contact::SetLastName(const std::string &s)  { _lastName = s; }
void Contact::SetSurname(const std::string &s)   { _surname = s; }
void Contact::SetPhone(const std::string &s)     { _phone = s; }
void Contact::SetSecret(const std::string &s)    { _secret = s; }

void Contact::SetContactInteractive() {
    std::string input;
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    SetFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    SetLastName(input);

    std::cout << "Enter nickname / surname: ";
    std::getline(std::cin, input);
    SetSurname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    SetPhone(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    SetSecret(input);
}

std::string Contact::GetFirstName() const { return _firstName; }
std::string Contact::GetLastName()  const { return _lastName; }
std::string Contact::GetSurname()   const { return _surname; }
std::string Contact::GetPhone()     const { return _phone; }
std::string Contact::GetSecret()    const { return _secret; }

void Contact::DisplayFull() const {
    std::cout << "First name : " << _firstName << std::endl;
    std::cout << "Last name  : " << _lastName  << std::endl;
    std::cout << "Surname    : " << _surname   << std::endl;
    std::cout << "Phone      : " << _phone     << std::endl;
    std::cout << "Secret     : " << _secret    << std::endl;
}
