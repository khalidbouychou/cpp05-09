#include "Form.hpp"
#include <stdio.h>
int main(void)
{
    try
    {
        Bureaucrat b("khbouych", 1);
        Form f("Bocal-Form", 1, 1);
        std::cout << b;
        std::cout << f;
        b.signForm(f);
        std::cout << f;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
