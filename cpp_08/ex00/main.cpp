#include "easyfind.hpp"
#include <iostream>





int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    try{
        int index = easyfind(v , 3);
        std::cout << "l9a liya l'index :" << index << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        int index = easyfind(v , 9000);
        std::cout << "l9a liya l'index :" << index << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    try
    {
        int index = easyfind(v, 1);
        std::cout << "Trouve a l'index : " << index << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        int index = easyfind(v, 5);
        std::cout << "Trouve a l'index : " << index << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}