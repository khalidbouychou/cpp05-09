/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:15:48 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/08 17:27:43 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
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
