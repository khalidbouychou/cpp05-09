
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Default Bureaucrat"), bgrade(150){}
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
const char *Bureaucrat::GradeTooHighException::what() const throw(){return ("Bureaucrat --->  Grade too high");}
const char *Bureaucrat::GradeTooLowException::what() const throw() { return ("Bureaucrat ---> Grade too low"); }
void Bureaucrat::incrementGrade()
{
    this->bgrade--;
    if (this->bgrade < 1)
        throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decrementGrade()
{
    if (this->bgrade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->bgrade++;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat  &b)
{
    if (this == &b)
        return *this;
    this->bgrade = b.bgrade;
    const_cast<std::string&>(this->name) = b.name;
    return *this;
}
