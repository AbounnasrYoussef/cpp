#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : current_index(0), stored_count(0) {}//C’est le constructeur par défaut de la classe PhoneBook.

void PhoneBook::addContact()
{
    std::string first, last, nick, phone, secret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, first);
    if (!std::cin) return; //vérifie si la saisie a échoué

    std::cout << "Enter last name: ";
    std::getline(std::cin, last);
    if (!std::cin) return;

    std::cout << "Enter nickname: ";
    std::getline(std::cin, nick);
    if (!std::cin) return;

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone);
    if (!std::cin) return;

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, secret);
    if (!std::cin) return;

    Contact tmp;
    tmp.setContact(first, last, nick, phone, secret);

    contacts[current_index % 8] = tmp;
    current_index++;
    if (stored_count < 8)
        stored_count++;
    
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContactsTable() const // indique que cette méthode ne modifie pas l’objet PhoneBook.
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < stored_count; i++)
    {
        Contact c = contacts[i];
        if (c.isEmpty()) continue;
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << c.truncateField(c.getFirstName()) << "|"
                  << std::setw(10) << c.truncateField(c.getLastName()) << "|"
                  << std::setw(10) << c.truncateField(c.getNickname()) << std::endl;
    }
}

void PhoneBook::showContactByIndex(int index) const
{
    if (index < 1 || index > stored_count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    const Contact &c = contacts[index - 1];
    std::cout << "First name: " << c.getFirstName() << std::endl;
    std::cout << "Last name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}
