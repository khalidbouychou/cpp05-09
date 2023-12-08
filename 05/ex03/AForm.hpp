/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:14:12 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/08 17:51:54 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm
{
    private:
        std::string const name;
        bool isSigned;
        int const gSign;
        int const gExecute;
    public:
        AForm();
        AForm(std::string const &_name, int const _gSign, int const _gExecute);
        AForm(AForm const &f);
        AForm& operator=(const AForm &f);
        virtual ~AForm();

        virtual std::string getName() const;
        bool getIsSigned() const;
        int getGSign() const;
        int getGExecute()const;

        void beSigned(Bureaucrat  &b);
        virtual void execute(Bureaucrat const &executor) const = 0;

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
        class FormNotSignedException : public std::exception
        {
            public:
               const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &o, AForm const &f);
