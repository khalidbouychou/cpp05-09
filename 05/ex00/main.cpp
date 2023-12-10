/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:16:07 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/08 17:29:35 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdio.h>
int main(void)
{
    try
    {
       Bureaucrat b("khbouych", 155);
       b.decrementGrade();
       std::cout << b;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    try
    {
       Bureaucrat b("khbouych", 1);
       b.incrementGrade();
       std::cout << b;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
