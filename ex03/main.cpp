/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:16:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 23:12:33 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void l(void)
{
    system("leaks ex03");
}
int main(void)
{
    atexit(l);
    try
    {
        Intern i1;
        Bureaucrat b("b1",1);
        AForm *f1 = i1.makeForm("robotomy request", "Bender");
        f1->beSigned(b);
        f1->execute(b);
        delete f1;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        exit(0);
    }
    std::cout << "-------------------------------------" << std::endl;
     try
    {
        Intern i2;
        Bureaucrat b("b2",1);
        AForm *f2 = i2.makeForm("shrubbery creation", "home");
        f2->beSigned(b);
        f2->execute(b);
        delete f2;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        exit(0);
    }
    std::cout << "-------------------------------------" << std::endl;
     try
    {
        Intern i3;
        Bureaucrat b("b3",1);
        AForm *f3 = i3.makeForm("presidential pardon", "wizara");
        f3->beSigned(b);
        f3->execute(b);
        delete f3;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        exit(0);
    }
    
}
