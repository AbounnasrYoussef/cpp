#include <iostream>
#include <string>
#include <cctype>


void to_upper(std::string str)
{
    for (int j = 0 ; str[j]  ; j++ )
    {
        std::cout <<  (char)std::toupper(str[j]);
    }
}


int main(int ac, char **av) {

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for(int  i = 1; i < ac ; i++)
            to_upper(av[i]);
        std::cout << std::endl;
    }
    return 0;
}