#include "Form.hpp"
#include <stdio.h>
int main(void)
{
    std::cout << "----------Signed-----------" << std::endl;
    try
    {
        Bureaucrat b("khbouych", 1);
        Form f("Bocal-Form", 10, 1);
        std::cout << b << std::endl;
        std::cout << "Form Grade : " << f.getGSign() << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "----------Not Signed-----------" << std::endl;
    try
    {
        Bureaucrat b("khbouych", 10);
        Form f("Bocal-Form",1, 1);
        std::cout << b << std::endl;
        std::cout << "Form Grade : " << f.getGSign() << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
