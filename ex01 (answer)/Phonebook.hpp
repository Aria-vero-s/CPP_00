#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class Phonebook {
public:
    Phonebook();
    ~Phonebook();

    void AddContact();     // interactive add
    void SearchContact();  // show table and let user choose index
    int  Exit();           // returns exit code (0)

private:
    static const int _maxContacts = 8;
    Contact _contacts[_maxContacts];
    int _count; // number of stored contacts (<= _maxContacts)
    int _next;  // next write position (wraps around)

    // helper for formatting summary column
    static std::string formatField(const std::string &s);
};

#endif // PHONEBOOK_HPP
