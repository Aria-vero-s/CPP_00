#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
public:
    Contact();
    Contact(const std::string &firstname,
            const std::string &lastname,
            const std::string &surname,
            const std::string &phone,
            const std::string &secret);
    ~Contact();

    // Setters
    void SetFirstName(const std::string &s);
    void SetLastName(const std::string &s);
    void SetSurname(const std::string &s);
    void SetPhone(const std::string &s);
    void SetSecret(const std::string &s);

    // Interactive helper: asks the user for all fields
    void SetContactInteractive();

    // Getters
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetSurname() const;
    std::string GetPhone() const;
    std::string GetSecret() const;

    // Display helpers
    void DisplayFull() const; // prints all fields
private:
    std::string _firstName;
    std::string _lastName;
    std::string _surname;
    std::string _phone;
    std::string _secret;
};

#endif // CONTACT_HPP
