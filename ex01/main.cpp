#include "Form.hpp"
#include <stdio.h>
int main(void)
{
    try
    {
        Bureaucrat b1("khbouych", 1);
        b1.decrementGrade();
        std::cout << b1;
        Form f1("Bocal-form",100,10);
        std::cout << "BEFORE --> "<< f1;
        f1.beSigned(b1);
        f1.signForm(b1);
        std::cout << "AFTER --> "<<f1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
