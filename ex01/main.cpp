#include "Form.hpp"
#include <stdio.h>
int main(void)
{
    Bureaucrat b1("khbouych", 1);
    std::cout << b1 << std::endl;
    std::cout << "-----------------------" << std::endl;
    Form f1("Bocal-form",1,1);
    f1.beSigned(b1);
    std::cout << "is signed :"<< f1.getIsSigned() << std::endl;
    f1.signForm(b1);
}
