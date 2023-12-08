/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:50:34 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 19:02:10 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(Intern const &src);
    ~Intern();
    Intern &operator=(Intern const &rhs);
    AForm *makeForm(std::string name, std::string target);
    int getindex(std::string name);
    class FormNotFoundException : public std::exception
    {
        const char *what() const throw();
    };
};
