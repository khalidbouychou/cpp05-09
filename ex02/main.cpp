/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:16:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 18:14:24 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main(void)
{
    try
    {
        Bureaucrat b("Bureaucrat", 4);
        // std::cout << "----------SHrobbery--------------" << std::endl;
        ShrubberyCreationForm Shrrubery("khbouych-Home");
        Shrrubery.beSigned(b);
        Shrrubery.execute(b);
        std::cout << "----------Robot--------------" << std::endl;
        RobotomyRequestForm robot("khbouych-robot");
        robot.beSigned(b);
        robot.execute(b);
        std::cout << "----------Presendent--------------" << std::endl;
        PresidentialPardonForm boss("khbouych-presedent");
        boss.beSigned(b);
        boss.execute(b);

        std::cout << "----------Bureaucrat execute form--------------" << std::endl;
             b.executeForm(Shrrubery);
             std::cout << "-------" << std::endl;
             b.executeForm(robot);
             std::cout << "-------" << std::endl;
             b.executeForm(boss);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
