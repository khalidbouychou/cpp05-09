/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:14:43 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/08 18:23:47 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Default Bureaucrat"), bgrade(150){
    if (this->bgrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->bgrade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(std::string const &_name, int bgrade): name(_name)
{   if (bgrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (bgrade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->bgrade = bgrade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &b): name(b.name),bgrade(b.bgrade){}
Bureaucrat::~Bureaucrat(){}
std::string Bureaucrat::getName() const {return(this->name);}
int Bureaucrat::getGrade() const {return(this->bgrade);}
std::ostream &operator<<(std::ostream &o,Bureaucrat const &b){o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl; return (o);}
const char *Bureaucrat::GradeTooHighException::what() const throw(){return ("Bureaucrat Grade Too High");}
const char *Bureaucrat::GradeTooLowException::what() const throw() { return ("Bureaucrat Grade Too Low"); }
void Bureaucrat::incrementGrade()
{
    this->bgrade--;
    if (this->bgrade < 1)
        throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decrementGrade()
{
    this->bgrade++;
    if (this->bgrade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat  &b)
{
    if (this == &b)
        return *this;
    this->bgrade = b.bgrade;
    const_cast<std::string&>(this->name) = b.name;
    return *this;
}
void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
