/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:40:37 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 17:54:28 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &_target);
        PresidentialPardonForm(PresidentialPardonForm const &f);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &f);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const &executor) const;
};