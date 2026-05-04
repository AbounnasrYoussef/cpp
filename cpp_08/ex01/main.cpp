#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "--- TEST 1 : main du sujet ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;  
    std::cout << sp.longestSpan() << std::endl;   


    std::cout << "--- TEST 2 : exception addNumber ---" << std::endl;
    try
    {
        sp.addNumber(42);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--- TEST 3 : exception shortestSpan ---" << std::endl;
    try
    {
        Span sp2 = Span(5);
        sp2.addNumber(1);
        sp2.shortestSpan(); 
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--- TEST 4 : addRange ---" << std::endl;
    Span sp3 = Span(10);
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    sp3.addRange(v.begin(), v.end());
    std::cout << sp3.shortestSpan() << std::endl;  
    std::cout << sp3.longestSpan() << std::endl;  

    
    std::cout << "--- TEST 5 : 10000 nombres ---" << std::endl;
    std::srand(std::time(NULL));
    Span sp4 = Span(10000);
    std::vector<int> big;
    for (int i = 0; i < 10000; i++)
        big.push_back(std::rand());
    sp4.addRange(big.begin(), big.end());
    std::cout << "shortestSpan : " << sp4.shortestSpan() << std::endl;
    std::cout << "longestSpan  : " << sp4.longestSpan()  << std::endl;

    return 0;
}