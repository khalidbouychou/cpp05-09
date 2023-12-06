/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:22:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 18:06:32 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137){this->target = "default";}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &_target) : AForm("ShrubberyForm", 145, 137){this->target = _target;}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &f) : AForm(f){this->target = f.target;}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f)
{
    if (this != &f)
        this->target = f.target;
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &exec) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormUntSignedException();
    if (exec.getGrade() > this->getGExecute())
        throw AForm::GradeTooLowException();
    std::ofstream ofs(this->target + "_shrubbery");
    ofs << "          *\n"
        << "         ***\n"
        << "        *****\n"
        << "       *******\n"
        << "      **********\n"
        << "     ************\n"
        << "    **************\n"
        << "   *****************\n"
        << "  ******KHBOUYCH*****\n"
        << " *********************\n"
        << "          |\n"
        << "          |\n"
        << "          |\n"
        << "          |\n"
        << "          |\n"
        << "          |\n"
        << "          |\n"
        << "          |\n";
    ofs.close();
    std::cout << "ShrubberyForm has been executed successfully" << std::endl;
}