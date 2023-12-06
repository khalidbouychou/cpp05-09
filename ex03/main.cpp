/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:16:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 19:35:41 by khbouych         ###   ########.fr       */
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
    Intern i;
    try
    {
        Bureaucrat b("b1",1);
        AForm *f1 = i.makeForm("robotomy request", "Bender");
        f1->beSigned(b);
        f1->execute(b);
        delete f1;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        exit(0);
    }
}
