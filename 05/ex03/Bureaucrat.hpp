/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:14:17 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/08 18:09:17 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        std::string const name;
        int bgrade;
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat const &b);
        Bureaucrat(std::string const &_name, int bgrade);
        Bureaucrat& operator=(const Bureaucrat &b);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &f);
        void executeForm(AForm const &form);

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
