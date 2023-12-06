/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:40:54 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 17:42:57 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){this->target = "default-presedent";}
PresidentialPardonForm::PresidentialPardonForm(std::string const &target_name) : AForm("PresidentialPardonForm", 25, 5){this->target = target_name;}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &f) : AForm(f){*this = f;}
PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &f)
{
    this->target = f.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormUntSignedException();
    else if (executor.getGrade() > this->getGExecute())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}