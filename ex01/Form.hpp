#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"


class Form
{
    private:
        std::string const name;
        bool isSigned;
        int const gSign;
        int const gExecute;
    public:
        Form();
        Form(std::string const &_name, int const _gSign, int const _gExecute);
        Form(Form const &f);
        Form& operator=(const Form &f);
        ~Form();
        std::string getName() const;
        bool getIsSigned() const;
        int getGSign() const;
        int getGExecute() const;
        void beSigned(Bureaucrat const &b);
        void signForm(Bureaucrat const &b);
        class GradeTooLowException: public std::exception
        {
            public:
               const char *what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
               const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &o, Form const &f);
