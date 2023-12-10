/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:12 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/06 16:15:15 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
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
        int getGExecute()const;
        void beSigned(Bureaucrat  &b);
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
