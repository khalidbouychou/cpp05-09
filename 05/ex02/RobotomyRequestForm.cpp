/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:02:34 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/08 18:06:24 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){this->target = "[ default-RobotomyRequestForm ]";}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target_name) : AForm("RobotomyRequestForm", 72, 45), target(target_name){}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &f) : AForm(f){*this = f;}
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &f)
{
    if (this != &f)
        this->target = f.target;
    return (*this);
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGExecute())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "zzzzzzzzzzzzz trrrrrr ..... (noises)" << std::endl;
        std::srand(std::time(NULL));
        int nrandom = rand();
        int var = nrandom % 2;

        if (!var)
            std::cout << "Robotomization of " << this->target << " [--failed--]" << std::endl;
        else
            std::cout << this->target << " has been robotomized [--successfully--]" << std::endl;
    }
}

