/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:16:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:18 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "------------------ROBOTOMY-------------------" << std::endl;
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
    }
    std::cout << "------------------SHRUBBERY-------------------" << std::endl;
    try
    {
        Intern i2;
        Bureaucrat b("b2",1);
        AForm *f2 = i2.makeForm("shrubbery creation", "target 2");
        f2->beSigned(b);
        f2->execute(b);
        delete f2;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------PARDON--------------------" << std::endl;
    try
    {
        Intern i3;
        Bureaucrat b("b3",1);
        AForm *f3 = i3.makeForm("presidential pardon", "target 3");
        f3->beSigned(b);
        f3->execute(b);
        delete f3;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
