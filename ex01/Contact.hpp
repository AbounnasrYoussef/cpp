#ifndef CONTACT_HPP
    #define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
    std::string prenom;
    std::string nom;
    std::string nick_name;
    std::string numero_tele;
    std::string secret;

public:
    // hade methobe bach initialisiwe contact
    void init_cont(std::string prenom,
                    std::string nom,
                    std::string nick_name,
                    std::string numero_tele,
                    std::string secret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    std::string tableau(std::string field) const;
    bool if_rien() const;
};













#endif