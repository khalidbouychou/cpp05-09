
#include "Form.hpp"

Form::Form():name("Default Form"), isSigned(false), gSign(150), gExecute(150){}
Form::Form(std::string const &_name, int const _gSign, int const _gExecute): name(_name), isSigned(false), gSign(_gSign), gExecute(_gExecute)
{
    if (this->gSign < 1 || this->gExecute < 1)
        throw Form::GradeTooHighException();
    else if (this->gSign > 150 || this->gExecute > 150)
        throw Form::GradeTooLowException();
}
Form::Form(Form const &f): name(f.name), isSigned(f.isSigned), gSign(f.gSign), gExecute(f.gExecute){}
Form::~Form(){}
std::string Form::getName() const {return(this->name);}
bool Form::getIsSigned() const {return(this->isSigned);}
int Form::getGSign() const {return(this->gSign);}
int Form::getGExecute() const {return(this->gExecute);}
void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gSign)
        throw Form::GradeTooLowException();
    else
        this->isSigned = true;
}
Form& Form::operator=(const Form  &f)
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

std::ostream &operator<<(std::ostream &o, Form const &f)
{
    o << "Form name: " << f.getName() << "| isSigned: " << f.getIsSigned() << "| grade toSign: " << f.getGSign() << "| grade toExecute: " << f.getGExecute() << std::endl;
    return (o);
}
const char *Form::GradeTooHighException::what() const throw(){return ("Form --->  Grade too high");}
const char *Form::GradeTooLowException::what() const throw() { return ("Form ---> Grade too low"); }
