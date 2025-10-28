#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int current_index;
    int stored_count;

public:
    PhoneBook();

    void addContact();
    void displayContactsTable() const;
    void showContactByIndex(int index) const;
};

#endif
