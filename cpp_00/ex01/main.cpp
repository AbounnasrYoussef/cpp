#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
        {
            phonebook.displayContactsTable();
            std::cout << "Enter index to view: ";
            std::string line;
            std::getline(std::cin, line);
            if (!std::cin) break;

            std::istringstream iss(line);
            int index;
            if (!(iss >> index))
                std::cout << "Invalid input." << std::endl;
            else
                phonebook.showContactByIndex(index);
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unknown command." << std::endl;
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
