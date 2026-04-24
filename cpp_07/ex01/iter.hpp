#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T, typename F>
void iter(T* array , size_t const n, F fonction)
{
    size_t i = 0;
    while (i < n)
    {
        fonction(array[i]);
        i++;
    }
}


template <typename T>
void print(T const &element)
{
    std::cout << "print : " << element << std::endl;
}

template <typename T>
void increment(T  &element)
{
    element++;
}




#endif