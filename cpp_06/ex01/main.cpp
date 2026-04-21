#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.number = 42;
    data.name   = "hello";

    std::cout << "Adresse originale   : " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Valeur serialisee   : " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Adresse deserialisee: " << ptr << std::endl;

    std::cout << std::endl;

    if (ptr == &data)
        std::cout << "OK : les pointeurs sont egaux !" << std::endl;
    else
        std::cout << "KO : les pointeurs sont differents !" << std::endl;

    std::cout << std::endl;

    std::cout << "data.number : " << ptr->number << std::endl;
    std::cout << "data.name   : " << ptr->name   << std::endl;

    return 0;
}