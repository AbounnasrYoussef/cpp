#include <iostream>




int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* PTR = &str;
    std::string& REF = str;



    std::cout<<"The memory address of the string variable: " << &str  <<std::endl;
    std::cout<<"The memory address held by stringPTR: " << PTR  <<std::endl;
    std::cout<<"The memory address held by stringREF: " << &REF  <<std::endl;


    std::cout<<"The value of the string variable: " << str  <<std::endl;
    std::cout<<"The value pointed to by stringPTR: " << *PTR  <<std::endl;
    std::cout<<"The value pointed to by stringREF: " << REF  <<std::endl;

}