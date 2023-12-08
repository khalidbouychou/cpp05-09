/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:17:09 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 17:54:38 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &_target);
        ShrubberyCreationForm(ShrubberyCreationForm const &f);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &f);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const &executor) const;
};