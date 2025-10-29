#include "Contact.hpp"
#include <iostream>

Contact::Contact() : is_initialized(false) {}

void Contact::setContact(const std::string &first,
                         const std::string &last,
                         const std::string &nick,
                         const std::string &phone,
                         const std::string &secret)
{
    if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty())
    {
        std::cout << "All fields must be non-empty!" << std::endl;
        is_initialized = false;
        return;
    }
    first_name = first;
    last_name = last;
    nickname = nick;
    phone_number = phone;
    darkest_secret = secret;
    is_initialized = true;
}

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phone_number; }
std::string Contact::getDarkestSecret() const { return darkest_secret; }

std::string Contact::truncateField(const std::string &field) const
{
    if (field.length() <= 10)
        return field;
    return field.substr(0, 9) + ".";
}

bool Contact::isEmpty() const
{
    return !is_initialized;
}
