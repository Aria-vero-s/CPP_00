#include "Phonebook.hpp"

Phonebook::Phonebook() {
    quantity = 0;
    oldest = 0;
}

int Phonebook::getQuantity() const {
    return quantity;
}

const Contact& Phonebook::getContact(int i) const {
    return arr[i];
}

void Phonebook::addContact(const Contact &c) {
    if (quantity < MAX) {
        arr[quantity] = c;
        quantity++;
    } else {
        arr[oldest] = c;
        oldest++;
        if (oldest == MAX)
            oldest = 0;
    }
}
