#include "Bureaucrat.hpp"
#include <stdio.h>
int main(void)
{
    try
    {
       Bureaucrat b("b", 155);
       b.decrementGrade();
       std::cout << b;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    try
    {
       Bureaucrat b("b", 149);
       std::cout << b;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
