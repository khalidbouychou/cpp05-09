/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:15:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/20 01:22:54 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(RPN const &src){*this = src;}
RPN::~RPN(){}
RPN &RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

void RPN::calculate (std::string args)
{
    while (args.length() > 0)
        std::cout << args << std::endl;
}