/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:14:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/08 18:23:14 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Form.hpp"
class Form;
class Bureaucrat
{
    private:
        std::string const name;
        int bgrade;
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat const &b);
        Bureaucrat(std::string const &_name, int bgrade);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &b);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &f);
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
std::ostream &operator<<(std::ostream &o, Bureaucrat const &b);
