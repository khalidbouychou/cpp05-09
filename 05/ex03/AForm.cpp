/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:14:02 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/08 17:51:54 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():name("Default AForm"), isSigned(false), gSign(150), gExecute(150){}
AForm::AForm(AForm const &f): name(f.name), isSigned(f.isSigned), gSign(f.gSign), gExecute(f.gExecute){}
AForm::~AForm(){}
std::string AForm::getName() const {return(this->name);}
int AForm::getGSign() const {return(this->gSign);}
bool AForm::getIsSigned() const {return(this->isSigned);}
int AForm::getGExecute() const {return(this->gExecute);}
AForm::AForm(std::string const &_name, int const _gSign, int const _gExecute): name(_name), isSigned(false), gSign(_gSign), gExecute(_gExecute)
{
    if (this->gSign < 1 || this->gExecute < 1)
        throw AForm::GradeTooHighException();
    else if (this->gSign > 150 || this->gExecute > 150)
        throw AForm::GradeTooLowException();
}
void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gSign)
        throw AForm::GradeTooLowException();
    else
        this->isSigned = true;
}
AForm& AForm::operator=(const AForm  &f)
{
    if (this == &f)
        return *this;
    const_cast<std::string&>(this->name) = f.name;
    this->isSigned = f.isSigned;
    const_cast<int&>(this->gSign) = f.gSign;
    const_cast<int&>(this->gExecute) = f.gExecute;
    this->isSigned = f.isSigned;
    return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &f)
{
    o << "AForm name: " << f.getName() << "| isSigned: " << f.getIsSigned() << "| grade toSign: " << f.getGSign() << "| grade toExecute: " << f.getGExecute() << std::endl;
    return (o);
}
const char *AForm::GradeTooHighException::what() const throw(){return ("(A)Form  Grade Too High");}
const char *AForm::GradeTooLowException::what() const throw() { return ("(A)Form Grade Too Low");}
const char *AForm::FormNotSignedException::what() const throw() { return ("(A)Form is not signed");}
