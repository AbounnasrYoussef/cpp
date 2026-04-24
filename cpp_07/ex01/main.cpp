#include "iter.hpp"
#include <iostream>
#include <string>

int main()
{
    
    int tab[] = {1, 2, 3, 4, 5};
    std::cout << "--- avant increment ---" << std::endl;
    iter(tab, 5, print<int>);
    iter(tab, 5, increment<int>);
    std::cout << "--- apres increment ---" << std::endl;
    iter(tab, 5, print<int>);

    
    std::string tabStr[] = {"hello", "world", "42"};
    std::cout << "--- string ---" << std::endl;
    iter(tabStr, 3, print<std::string>);

    
    const int tabConst[] = {10, 20, 30};
    std::cout << "--- const int ---" << std::endl;
    iter(tabConst, 3, print<int>);

    return 0;
}