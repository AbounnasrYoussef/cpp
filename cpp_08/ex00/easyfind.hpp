#ifndef EASYFIND_HPP
#define  EASYFIND_HPP


#include <stdexcept>
#include <vector>



template<typename T>
int easyfind(T &container , int value)
{
    for(int i = 0; i < (int)container.size(); i++)
    {
        if (container[i] == value)
            return i;
    }
    throw std::runtime_error( " value not found ");
}




#endif