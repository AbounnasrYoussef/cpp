#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Youssef", 42);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.decrementGrade();
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("ErrorTest", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
