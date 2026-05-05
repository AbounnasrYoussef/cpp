#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "--- TEST 1 : main du sujet ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; 
    mstack.pop();
    std::cout << mstack.size() << std::endl; 
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    
    std::cout << "--- TEST 2 : empty et size ---" << std::endl;
    MutantStack<int> ms;
    std::cout << "empty : " << ms.empty() << std::endl;  
    ms.push(1);
    ms.push(2);
    ms.push(3);
    std::cout << "size  : " << ms.size() << std::endl;   
    std::cout << "empty : " << ms.empty() << std::endl;  


    std::cout << "--- TEST 5 : modification via iterateur ---" << std::endl;
    MutantStack<int> ms4;
    ms4.push(10);
    ms4.push(20);
    ms4.push(30);
    MutantStack<int>::iterator it4 = ms4.begin();
    *it4 = 100; 
    it4 = ms4.begin();
    while (it4 != ms4.end())
    {
        std::cout << *it4 << std::endl;  
        ++it4;
    }

    std::cout << "--- TEST 6 : comparaison avec std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator itl = lst.begin();
    while (itl != lst.end())
    {
        std::cout << *itl << std::endl;
        ++itl;
    }

    std::cout << "--- TEST 7 : MutantStack<string> ---" << std::endl;
    MutantStack<std::string> ms5;
    ms5.push("hello");
    ms5.push("world");
    ms5.push("42");
    MutantStack<std::string>::iterator it5 = ms5.begin();
    while (it5 != ms5.end())
    {
        std::cout << *it5 << std::endl;
        ++it5;
    }

    return 0;
}