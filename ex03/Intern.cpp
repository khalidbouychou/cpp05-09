/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:57:39 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 19:03:42 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int Intern::getindex(std::string name)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == name)
            return (i);
    }
    return (-1);
}
AForm *Intern::makeForm(std::string name, std::string target)
{
    int index = getindex(name);
    switch(index)
    {
        case 0:
            std::cout << "Intern creates " << name << std::endl;
            return (new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Intern creates " << name << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << name << std::endl;
            return (new PresidentialPardonForm(target));
        default:
            throw FormNotFoundException();
    }
}

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
    *this = src;
}

Intern::~Intern()
{
}


Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return (*this);
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}