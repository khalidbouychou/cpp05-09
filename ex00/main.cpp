#include "Bureaucrat.hpp"
#include <stdio.h>
int main(void)
{
    try
    {
       Bureaucrat b("khbouych", 155);
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
       Bureaucrat b("khbouych", 149);
       std::cout << b;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
